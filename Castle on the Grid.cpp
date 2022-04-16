#include <bits/stdc++.h>

using namespace std;




string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


char* readline();
char** split_string(char*);

typedef pair<int, int> Node;
struct NodeDistance 
{
    Node node;
    int distance;
};

const int DIR_X[] = {0, 1,  0, -1};
const int DIR_Y[] = {1, 0, -1,  0};




/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    Node start(startX,startY), end(goalX,goalY);




    int grid_size = int(grid.size());
    vector<vector<bool>> visited(grid_size, vector<bool>(grid_size));

    queue<NodeDistance> q_distances;

    q_distances.push({start, 0});
    visited[start.first][start.second] = true;

    while (!q_distances.empty()) 
    {
        NodeDistance cnd = q_distances.front();
        q_distances.pop();

        if (cnd.node == end)
            return cnd.distance;

        int x = cnd.node.first;
        int y = cnd.node.second;

        for (int dir = 0; dir < 4; dir++) 
        {
            int dx = DIR_X[dir], dy = DIR_Y[dir];

            for (int i = x + dx, j = y + dy;
                 i < grid_size && i >= 0 && j < grid_size && j >= 0 && grid[i][j] == '.';
                 i = i + dx, j = j + dy) 
            {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    q_distances.push({{i, j}, cnd.distance + 1});
                }
            }
        }
    }
    return -1;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
