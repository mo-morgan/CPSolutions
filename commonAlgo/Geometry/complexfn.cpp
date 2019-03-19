double dot(pt a, pt b) { return real(conj(a)*b); }
double lp_dist(pt a, pt b, pt p) {
    pt u = (b-a);
    pt v = (p-a);
    pt m = dot(u,v)/dot(u,u) * u + a;
    return abs(m-p);
}