bool collinear(pll a, pll b) {
        return a.first * b.second == a.second * b.first;
}

bool collinear(pll a, pll b, pll c) {
        return collinear(
                pll(b.first - a.first, b.second - a.second),
                pll(c.first - a.first, c.second - a.second)
        );
}