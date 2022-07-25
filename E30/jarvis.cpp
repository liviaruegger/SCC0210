#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
    long long x;
    long long y;
};

double distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int orientation(Point p, Point q, Point r)
{
    int val = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));

    if (val == 0) return 0; // são colineares
    return (val > 0) ? 1 : 2; // horário (1) ou anti-horário (2)
}

vector<Point> convex_hull_jarvis_alg(Point points[], int n)
{
    vector<Point> hull;

    if (n < 3) return hull;

    int leftmost = 0; // índice do ponto mais à esquerda
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftmost].x)
            leftmost = i;

    int p = leftmost, q;
    do
    {
        hull.push_back(points[p]);

        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != leftmost);

    return hull;
}

int main()
{
    int n_sheeps;
    cin >> n_sheeps;

    Point sheeps[n_sheeps];
    for (int i = 0; i < n_sheeps; i++)
    {
        cin >> sheeps[i].x;
        cin >> sheeps[i].y;
    }

    vector<Point> hull = convex_hull_jarvis_alg(sheeps, n_sheeps);

    double perimeter = 0.0;
    for (int i = 0; i < (int)hull.size(); i++)
        perimeter += distance(hull[i], hull[(i + 1) % hull.size()]);

    printf("%.6lf\n", perimeter);

    return 0;
}