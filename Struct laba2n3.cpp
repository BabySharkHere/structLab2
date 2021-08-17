/*B-7.
Из орграфа удалить все вершины, из которых недостижима заданная.*/

#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");

	const int width = 5;
	const int height = 5;

	int graph[width][height] = {
		{1000, 3, 6, 7, 1000},
		{1000, 1000, 1000, 1000, 4},
		{1000, 1000, 1000, 8, 5},
		{1000, 1000, 1000, 1000, 1000},
		{1000, 1000, 1000, 1000, 1000}
	};

	int z[width - 1];

	cout << "Исходный граф матрицей весов: " << endl;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			cout << "g[" << i << "][" << j << "] " << graph[i][j] << "\t";
		cout << endl;
	}

	int A;

	cout << "Введите вершину, которую необходимо достичь" << endl;
	cin >> A;

	cout << "Вершина, которую необходимо достичь = " << A << "\nЕё значение в матрице в первом столбце: " << graph[A][0] << endl;

	int temp = A;
	int t = 0;

	temp = 0;

	for (int d = 0; d < width; d++) {
		
		if (temp == 5) {
			break;
		}
		int distance[width], count, index, i, u, m = temp;
		bool visited[width];
		for (i = 0; i < width; i++)
		{
			distance[i] = 1000;
			visited[i] = false;
		}
		distance[temp] = 0;
		for (count = 0; count < width; count++)
		{
			int min = 1000;
			for (i = 0; i < width; i++)
				if (!visited[i] && distance[i] <= min)
				{
					min = distance[i];
					index = i;
				}
			u = index;
			visited[u] = true;
			for (i = 0; i < width; i++)
				if (!visited[i] && graph[u][i] && distance[u] != 1000 && distance[u] + graph[u][i] < distance[i])
					distance[i] = distance[u] + graph[u][i];
		}
		/*cout << endl << "Стоимость пути из начальной вершины до остальных:" << endl;
		int den = 0;
		for (i = 0; i < width; i++)
			if (distance[i] == 0)
				cout << m << " -> " << i << " = " << "маршрут недоступен" << endl;
			else if (distance[i] != 1000)
				cout << m << " -> " << i << " = " << distance[i] << endl;
			else if (distance[i] == 1000) {
				cout << m << "-> " << i << " = МАРШРУТА НЕТ" << endl;
			}*/
		temp++;
		if (distance[A] == 1000) {
			z[t] = m;
			t++;
		}
	}

	cout << "Вершины из которых недостижима заданная" << endl;
	for (int i = 0; i < t; i++)
		cout << "z[" << i << "] " << z[i] << endl;

	int den;

	for (int d = 0; d < t; d++) {
		den = z[d];
		if (den >= 0) {
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					graph[den][j] = 1001;
					graph[i][den] = 1001;
				}
			}

		}
	}
	
	cout << endl << "Изменённая матрица:" << endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (graph[i][j] != 1001) {
				cout << "[" << i << "][" << j << "] " << graph[i][j] << "\t";
			}
		}
		cout << endl;
	}
	
	return 0;

	
}
