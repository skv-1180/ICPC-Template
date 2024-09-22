int Q = 0;
int query(int p, int X) {
    cout << "? " << p << " " << X << endl;
    int Y; cin >> Y;
    if (Y == -1) exit(0);
    Q++;
    return Y;
}
void finalAns(int x) {
    cout << "! " << x << endl;
}
//#define endl '\n'