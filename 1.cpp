int gcd(int a, int b, int& x, int& y) {
    //Extended euclidean algorithm. Apart from giving the g=gcd(A,B), it gives an x and y which are solutions to the equation Ax+By=G. 
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g){
    
    g=gcd(abs(a), abs(b), x0, y0);  //1. Apply extended Euclidean Algorithms
    if(c%g)                         //if it's not 0 then ax+by=c has no integral solution
        return false;

    x0 *=c/g;                       //2
    y0 *=c/g;                       //3

    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}
void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    
    if(a==0 && b==0 && c==0) return(maxx-minx+1)*(maxy-miny+1);   //this is the trivial case 0+0=0 and all numbers in the interval will satisfy the equation

        else if(a==0 && b==0) return 0;                        //only a and b are 0 => 0=C

        else if(a==0){                                              //only a is 0, By=C
            if(c%b!=0 || miny>c/b || maxy<c/b) return 0;           //Ans is 0 when y doesn't exist ie. C doesn't divide B; or C does divide B but C/B doesn't fall in the given interval
            else return (maxx-minx+1);                             //if such a y exists in the given interval, then it can be paired with any x in the given interval     }
        }
        else if(b==0){                                              //Ax=C, same thing as above.
            if(c%a!=0 || minx>c/a || maxx<c/a) return 0;
            else return (maxy-miny+1);
        }

    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))  //if there doesn't exist any solution of Ax+By=C then return 0
        return 0;

    //for the below part, I suggest reading the reference link

    a /= g;                                                                          
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
    if (lx > rx)
        return 0;

    return (rx - lx) / abs(b) + 1;
}
