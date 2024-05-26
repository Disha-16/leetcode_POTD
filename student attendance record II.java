class Solution {
    private static final int MOD = 1000000007;

    private int[][] matmul(int[][] A, int[][] B) {
        int[][] C = new int[6][6];
        for (int k = 0; k < 6; k++) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    C[i][j] = (int) ((C[i][j] + (long) A[i][k] * B[k][j]) % MOD);
                }
            }
        }
        return C;
    }

    private int[][] pow(int[][] A, int n) {
        if (n == 1) {
            return A;
        }
        int[][] t = pow(A, n / 2);
        t = matmul(t, t);
        if (n % 2 != 0) {
            t = matmul(t, A);
        }
        return t;
    }
    public int checkRecord(int n) {
           int[][] baseMatrix = {
            {1, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0}
        };

        int[][] resultMatrix = pow(baseMatrix, n);

        int result = 0;
        for (int i = 0; i < 6; i++) {
            result = (result + resultMatrix[i][0]) % MOD;
        }
        return result;
    }
}
