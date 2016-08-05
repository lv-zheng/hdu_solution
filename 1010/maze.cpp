#include <cstring>
#include <iostream>

int board[10][10];
bool vis[10][10];

int n, m, t;

int sx, sy, tx, ty;

int dir[4][2] = {
	{0, -1},
	{0, 1},
	{-1, 0},
	{1, 0}
};

bool dfs(int cx, int cy, int depth)
{
	if (depth == 0)
		return cx == tx && cy == ty;
	vis[cx][cy] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = cx + dir[i][0], ny = cy + dir[i][1];
		if (board[nx][ny] || vis[nx][ny])
			continue;
		if (dfs(nx, ny, depth - 1))
			return true;
	}
	vis[cx][cy] = false;
	return false;
}

void work()
{
	std::memset(board, -1, sizeof(board));
	std::memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char ch;
			std::cin >> ch;
			if (ch == 'X') {
				board[i][j] = -1;
			} else {
				if (ch == 'S')
					sx = i, sy = j;
				else if (ch == 'D')
					tx = i, ty = j;
				board[i][j] = 0;
			}
		}
	}
	if ((sx + sy - tx - ty + t) % 2) {
		std::cout << "NO" << std::endl;
		return;
	}
	bool res = dfs(sx, sy, t);
	if (res)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}

int main()
{
	while (std::cin >> n >> m >> t && n)
		work();
	return 0;
}
