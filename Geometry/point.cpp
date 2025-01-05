struct P {
	int x, y;
	void read() {
		cin >> x >> y;
	}
	P operator -(const P& b) const {
		return P{x - b.x, y - b.y};
	}
	void operator -=(const P& b) {
		x -= b.x;
		y -= b.y;
	}
	long long operator *(const P& b) const {
		return (long long) x * b.y - (long long) y * b.x;
	}
	long long triangle(const P& b, const P& c) const {
		return (b - *this) * (c - *this);
	}
	bool operator < (const P& b)const {
        return make_pair(x,y) < make_pair(b.x,b.y);
    }
};