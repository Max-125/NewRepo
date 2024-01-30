
#include <iostream>

double count_det_M11(double matrix[4][4]) {
    return matrix[1][1] * (matrix[2][2] * matrix[3][3] - matrix[2][3] * matrix[3][2]) -
        matrix[1][2] * (matrix[2][1] * matrix[3][3] - matrix[2][3] * matrix[3][1]) +
        matrix[1][3] * (matrix[2][1] * matrix[3][2] - matrix[2][2] * matrix[3][1]);
}

double count_det_M12(double matrix[4][4]) {
    return -(matrix[1][0] * (matrix[2][2] * matrix[3][3] - matrix[2][3] * matrix[3][2]) -
        matrix[1][2] * (matrix[2][0] * matrix[3][3] - matrix[2][3] * matrix[3][0]) +
        matrix[1][3] * (matrix[2][0] * matrix[3][2] - matrix[2][2] * matrix[3][0]));
}

double count_det_M13(double matrix[4][4]) {
    return matrix[1][0] * (matrix[2][1] * matrix[3][3] - matrix[2][3] * matrix[3][1]) -
        matrix[1][1] * (matrix[2][0] * matrix[3][3] - matrix[2][3] * matrix[3][0]) +
        matrix[1][3] * (matrix[2][0] * matrix[3][1] - matrix[2][1] * matrix[3][0]);
}

double count_det_M14(double matrix[4][4]) {
    return -(matrix[1][0] * (matrix[2][1] * matrix[3][2] - matrix[2][2] * matrix[3][1]) -
        matrix[1][1] * (matrix[2][0] * matrix[3][2] - matrix[2][2] * matrix[3][0]) +
        matrix[1][2] * (matrix[2][0] * matrix[3][1] - matrix[2][1] * matrix[3][0]));
}

double det4_by_4(double matrix[4][4]) {
    double det_M11 = count_det_M11(matrix);
    double det_M12 = count_det_M12(matrix);
    double det_M13 = count_det_M13(matrix);
    double det_M14 = count_det_M14(matrix);

    return matrix[0][0] * det_M11 + matrix[0][1] * det_M12 + matrix[0][2] * det_M13 + matrix[0][3] * det_M14;
}

int main() {
    double matrix[4][4] = {
        {1, 45, 3, 4},
        {5, 8, 7, 10},
        {18, 13, 4, 23},
        {13, 24, 15, 26}
    };

    double result = det4_by_4(matrix);

    std::cout << "Result = " << result << std::endl;
    return 0;
}