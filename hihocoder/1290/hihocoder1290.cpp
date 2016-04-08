#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n, m;

#define MAXB 150
#define MAX 0x3f3f3f3f

char board[MAXB][MAXB];

int stat[MAXB][MAXB][2]; // 0 R 1 D

int main() {
//  freopen("acm.in", "r", stdin);
  while(scanf("%d %d", &n ,&m) != EOF) {
    for(int i = 1; i <=n ; i++) {
      char s[MAXB];
      scanf("%s", s);
      for(int j = 1; j <= m; j++) {
        board[i][j] = s[j - 1];
      }
    }
   for(int i = 1 ; i <= n ; i++)
      board[i][m + 1] = 'b';
   for(int j = 1; j <= m; j++)
      board[n + 1][j] = 'b';
    for(int i = 0; i < MAXB; i++) {
      for(int j = 0; j < MAXB; j++) {
        stat[i][j][0] = MAX;
        stat[i][j][1] = MAX;
      }
    }
    stat[1][0][0] = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        // 最后加上个这个节点是不是 b 
        stat[i][j][0] = min((int)(stat[i - 1][j][1] + (board[i + 1][j] == '.')), stat[i][j - 1][0]);
        stat[i][j][1] = min((int)(stat[i][j - 1][0] + (board[i][j + 1] == '.')), stat[i - 1][j][1]);
        int change = board[i][j] == 'b';
        stat[i][j][0] += change;
        stat[i][j][1] += change;
      }
    }
    int ans = min(stat[n][m][0], stat[n][m][1]);
    printf("%d\n", ans);
  }
  return 0;
}
