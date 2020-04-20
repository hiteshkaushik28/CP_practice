#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    int N, K, P;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> K >> P;
        vector<vector<int>> beauty (N+1, vector<int> (K+1, 0));
        vector<vector<int>> beauty_prefix_sum (N+1, vector<int> (K+1, 0));
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= K; ++j) {
                cin >> beauty[i][j];
                beauty_prefix_sum[i][j] = beauty_prefix_sum[i][j-1] + beauty[i][j];
            }

        vector<vector<int>> dp (N+1, vector<int>(P+1, 0));
        for (int stack_num = 1; stack_num <= N; ++stack_num) {
            int max_possible_plates = min(stack_num*K, P);
            for (int plates_reqd = 1; plates_reqd <= max_possible_plates; ++plates_reqd) {
                int max_prev_row_plates = (stack_num-1)*K;
                int min_plates_from_curr_row = max(0, plates_reqd-(max_prev_row_plates));
                int max_plates_from_curr_row = min(plates_reqd, K);
                for (int k = min_plates_from_curr_row; k <= max_plates_from_curr_row; ++k)
                    dp[stack_num][plates_reqd] = max(dp[stack_num][plates_reqd], beauty_prefix_sum[stack_num][k] + dp[stack_num-1][plates_reqd-k]);
            }
        }
        cout << "Case #" << tc << ": " << dp[N][P] << endl;
    }
    return 0;
}