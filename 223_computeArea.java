class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int lx = Math.max(A, E);
        int by = Math.max(B, F);
        int rx = Math.min(C, G);
        int ty = Math.min(D, H);

        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        
        if (E > C || F > D || G < A || H < B) {
            return area1 + area2;
        }

        return area1 + area2 - (rx - lx) * (ty - by);
    }
}