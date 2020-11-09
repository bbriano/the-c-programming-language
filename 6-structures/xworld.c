#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point pos;
    int w;
    int h;
};

struct point make_point(int x, int y) {
    struct point res;
    res.x = x;
    res.y = y;
    return res;
}

struct point add_point(struct point a, struct point b) {
    struct point res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

struct point negate_point(struct point p) {
    struct point res;
    res.x = -p.x;
    res.y = -p.y;
    return res;
}

int pt_in_rect(struct point p, struct rect r) {
    return p.x >= r.pos.x && p.x < r.pos.x + r.w
        && p.y >= r.pos.y && p.y < r.pos.y + r.h;
}

int rect_in_rect(struct rect r, struct rect w) {
    struct point end;
    end.x = r.pos.x + r.w;
    end.y = r.pos.y + r.h;
    return pt_in_rect(r.pos, w) && pt_in_rect(end, w);
}

float dist(struct point a, struct point b) {
    return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
}

struct point middle(struct point a, struct point b) {
    struct point res;
    res.x = (a.x + b.x) / 2;
    res.y = (a.y + b.y) / 2;
    return res;
}

void draw(struct rect window, struct rect *rs, int nrs, struct point *pts, int npts) {
    // Create and initialise canvas
    char canvas[window.h][window.w+1];
    for (int h = 0; h < window.h; h++) {
        for (int w = 0; w < window.w; w++) {
            canvas[h][w] = ' ';
        }
        canvas[h][window.w] = '\0';
    }

    // Draw rects
    for (int i = 0; i < nrs; i++) {
        for (int x = rs[i].pos.x; x < rs[i].pos.x + rs[i].w; x++) {
            for (int y = rs[i].pos.y; y < rs[i].pos.y + rs[i].h; y++) {
                struct point pt = { x, y };
                if (!pt_in_rect(pt, window)) continue;
                canvas[y][x] = '.';
            }
        }
    }

    // Draw points
    for (int i = 0; i < npts; i++) {
        if (!pt_in_rect(pts[i], window)) continue;
        canvas[pts[i].y][pts[i].x] = 'x';
    }

    // Print canvas
    for (int h = 0; h < window.h; h++) {
        printf("%s\n", canvas[h]);
    }
}

int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

void move_point_rand(struct rect *boundary, struct point *p) {
    int xc = rand_range(-2, 2);
    int yc = rand_range(-2, 2);
    p->x += xc;
    p->y += yc;
    if (!pt_in_rect(*p, *boundary)) {
        p->x -= xc;
        p->y -= yc;
    }
}

int main() {
    struct point *pts = malloc(sizeof(struct rect) * 100);
    struct rect *rs = malloc(sizeof(struct rect) * 100);
    struct point *ppts = pts;
    struct rect *rrs = rs;

    struct rect window = { make_point(0, 0), 120, 40 };

    *rrs++ = (struct rect) { make_point(0, 0), window.w, 1 };
    *rrs++ = (struct rect) { make_point(0, window.h-1), window.w, 1 };
    *rrs++ = (struct rect) { make_point(0, 0), 1, window.h };
    *rrs++ = (struct rect) { make_point(window.w-1, 0), 1, window.h };
    for (int i = 0; i < 20; i++) {
        int x = rand_range(0, window.w);
        int y = rand_range(0, window.h);
        *ppts++ = make_point(x, y);
    }

    while (1) {
        /* window = (struct rect) { make_point(0, 0), 100, 40 }; */

        // Move
        for (struct point *p = pts; p <= ppts; p++) {
            move_point_rand(&window, p);
        }

        // Draw
        system("clear");
        draw(window, rs, rrs-rs, pts, ppts-pts);
        usleep(100000);
    }

    free(rs);
    free(pts);
}
