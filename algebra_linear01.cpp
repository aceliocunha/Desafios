#include<bits/stdc++.h>
using namespace std;
using Vec = vector<double>;
using Mat = vector<Vec>;


double dot(const Vec& a, const Vec& b) {
    return transform_reduce(a.begin(), a.end(), b.begin(), 0.0);
}

double norm(const Vec& v) {
    return sqrt(dot(v, v));
}


Vec operator+(const Vec& a, const Vec& b) {

    Vec r(a.size());
    transform(a.begin(), a.end(), b.begin(), r.begin(), plus<>{});
    return r;

}

Vec operator*(double k, Vec v) {
    ranges::for_each(v, [k](double& x){x*=k; });
}


Mat zeros(size_t m, size_t n) {
    return Mat(m, Vec(n, 0.0));
}

Mat identity(size_t n) {
    Mat I = zeros(n, n);
    for (size_t i = 0; i<n; ++i) I[i][i] = 1.0;
    return I;
}
Mat transpose(const Mat& A) {
    size_t m = A.size(), n = A[0].size();
    Mat T = zeros(n, m);
    for (size_t i = 0; i<m; ++i)
        for (size_t j = 0; j<n; ++j)
            T[j][i] = A[i][j];
    return T;
}
Mat operator+(const Mat& A, const Mat& B) {
    Mat C = A;
    for (size_t i = 0; i<A.size(); ++i)
        for (size_t j= 0; j<A[0].size(); ++j)
            C[i][j] += B[i][j];
    return C;
}
Mat operator+(double k, Mat M) {
    for (auto& row: M)
        ranges::for_each(row, [k](double& x){x*=k;});
    return M;
}
void print(const Mat& A) {
    for (auto& row: A) {
        for (double v: row)
            cout<<setw(10)<<fixed<<setprecision(4)<<v<<' ';
        cout<<'\n';
    }
    cout<<'\n';
}

int main() {
    Vec v1 = {1, 2, 3}, v2 = {4, 5, 6};
    cout<<"Produto(v1, v2) = "<<dot(v1, v2)<<"\n";
    cout<<"Norm(v1) = "<<norm(v1) <<"\n\n";
    Mat A = {{4, 2, 1},
            {0, 5, 3},
            {0, 0, 6}};
    cout<<"Matriz A:\n"; print(A);
    Mat Tr = transpose(A);
    cout<<"Transposta de A = ";print(Tr);
    return 0;
}
