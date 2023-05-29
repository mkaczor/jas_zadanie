//Jan Zaranski
#include <iostream>

int cube[32][32][32]; // 3D array for data

int cuboid(int l, int v, int p, int h, int w, int d, int edge) {
    int sum = 0;

    for (int i = l; i < l + h && i < edge; ++i) {
        for (int j = v; j < v + w && j < edge; ++j) {
            for (int k = p; k < p + d && k < edge; ++k) {
                sum += cube[i][j][k];
            }
        }
    }

    return sum;
}

int tetrahedron(int l, int v, int p, int e, int edge) {
    int sum = 0;

    for (int i = l; i <= l + e && i < edge; ++i) {
        for (int j = v; j <= v + e && j < edge; ++j) {
            for (int k = p; k <= p + e && k < edge; ++k) {
                if (i - l + j - v + k - p <= e) {
                    sum += cube[i][j][k];
                }
            }
        }
    }

    return sum;
}


int octant(int l, int v, int p, int r, int edge) {
    int sum = 0;

    for (int i = l - r; i <= l + r && i < edge; ++i) {
        if (i < 0) continue;

        for (int j = v - r; j <= v + r && j < edge; ++j) {
            if (j < 0) continue;

            for (int k = p - r; k <= p + r && k < edge; ++k) {
                if (k < 0) continue;

                if ((i - l) * (i - l) + (j - v) * (j - v) + (k - p) * (k - p) <= r * r) {
                    sum += cube[i][j][k];
                }
            }
        }
    }

    return sum;
}

int determinant(char k, int i, int edge) {
    int sum = 0;

    if (k == '1') {
        for (int j = 0; j < edge; ++j) {
            for (int k = 0; k < edge; ++k) {
                sum += cube[i][j][k];
            }
        }
    } else if (k == 'v') {
        for (int i = 0; i < edge; ++i) {
            for (int k = 0; k < edge; ++k) {
                sum += cube[i][i][k];
            }
        }
    } else if (k == 'p') {
        for (int i = 0; i < edge; ++i) {
            for (int j = 0; j < edge; ++j) {
                sum += cube[i][j][k];
            }
        }
    }

    return sum;
}

int main() {
    int edge; // edge length of the data cube
    std::cin >> edge;

    // Input cube data
        for (int i = 0; i < edge; ++i) {
        for (int j = 0; j < edge; ++j) {
            for (int k = 0; k < edge; ++k) {
                std::cin >> cube[i][j][k];
            }
        }
    }

    char op; // operation code

    while (std::cin >> op) {
        switch (op) {
            case 'C': {
                int l, v, p, h, w, d;
                std::cin >> l >> v >> p >> h >> w >> d;
                std::cout << cuboid(l, v, p, h, w, d, edge) << std::endl;
                break;
            }

            case 'T': {
                int l, v, p, e;
                std::cin >> l >> v >> p >> e;
                std::cout << tetrahedron(l, v, p, e, edge) << std::endl;
                break;
            }

            case 'O': {
                int l, v, p, r;
                std::cin >> l >> v >> p >> r;
                std::cout << octant(l, v, p, r, edge) << std::endl;
                break;
            }

            case 'D': {
                char k;
                int i;
                std::cin >> k >> i;
                std::cout << determinant(k, i, edge) << std::endl;
                break;
            }

            case 'E': {
                return 0;
            }

            default:
                std::cerr << "Invalid operation." << std::endl;
        }
    }
}
