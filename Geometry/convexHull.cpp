//https://www.youtube.com/watch?v=G9QTjWtK_TQ
struct P {
	long long x, y;
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

vector<P> getConvexHull(vector<P>points, int n){
    sort(points.begin(),points.end());

    vector<P>upperHull;
    for(P C: points){
        while(upperHull.size() >= 2){
            P A = upperHull.end()[-2];
            P B = upperHull.end()[-1];
            if(A.triangle(B,C) <= 0){ // B on the left from C, or collinear   
                /*                 C
                        B 
                    A                 */
                break;
            }
            upperHull.pop_back();
        }
        upperHull.push_back(C);
    }

    reverse(points.begin(), points.end());
    vector<P>lowerHull;
    for(P C: points){
        while(lowerHull.size() >= 2){
            P A = lowerHull.end()[-2];
            P B = lowerHull.end()[-1];
            if(A.triangle(B,C) <= 0){ 
                break;
            }
            lowerHull.pop_back();
        }
        lowerHull.push_back(C);
    }

    vector<P> convexHull = upperHull;
    convexHull.pop_back();
    for(P C:lowerHull){
        convexHull.push_back(C);
    }
    convexHull.pop_back();
    return convexHull;
}