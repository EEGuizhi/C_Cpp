// Title: Checkers, Verdict: Accepted, Run Time: 0.000
#include <stdio.h>
#include <stdlib.h>

int main() {
    char board[100][100];
    int T, N, i, x, y, x0, y0;

    scanf("%d", &T);
    for(i=0; i<T; i++) {
        long long unsigned ways[100][100] = {0};

        scanf("%d", &N);  // inputs
        for(y=N-1; y>=0; y--) {
            getchar();  // for '\n'
            for(x=0; x<N; x++) {
                board[x][y] = getchar();
                if(board[x][y] == 'W') {
                    x0 = x;
                    y0 = y;
                }
            }
        }

        for(y=N-1; y>=y0; y--) {
            for(x=0; x<N; x++) {
                if(board[x][y] != 'B') {
                    if(y == N-1) {
                        ways[x][y] = 1;
                    }
                    else {
                        if(x-1 >= 0 && y+1 < N) {  // to left up
                            if(board[x-1][y+1] == '.') {
                                ways[x][y] += ways[x-1][y+1];
                            }
                            else if(x-2 >= 0 && y+2 < N && board[x-2][y+2] == '.') {
                                ways[x][y] += ways[x-2][y+2];
                            }
                        }

                        if(x+1 < N && y+1 < N) {  // to right up
                            if(board[x+1][y+1] == '.') {
                                ways[x][y] += ways[x+1][y+1];
                            }
                            else if(x+2 < N && y+2 < N && board[x+2][y+2] == '.') {
                                ways[x][y] += ways[x+2][y+2];
                            }
                        }

                        if(ways[x][y] > 1000007) {
                            ways[x][y] %= 1000007;
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", i+1, ways[x0][y0] % 1000007);
    }

    return 0;
}
