#include <iostream>
#include "ceres/ceres.h"

/**
 *
1：构建cost fuction。这个部分需要使用仿函数（functor）这一技巧来实现，做法是定义一个cost function的结构体，在结构体内重载（）运算符
2：通过代价函数构建待求解的优化问题。
3：配置求解器参数并求解问题，这个步骤就是设置方程怎么求解、求解过程是否输出等，然后调用一下Solve方法。
更多样例参考 https://blog.csdn.net/cqrtxwd/article/details/78956227
 （多个输入、离散点拟合等）
 */

/*
 * 样例：求x使得1/2*(10−x)^2取到最小值
 */
using namespace std;

struct CostFunctor {
    template<typename T>
    bool operator()(const T *const x, T *residual) const {
        residual[0] = T(10.0) - x[0];
        return true;
    }
};


int main(int argc, char **argv) {
    //1.设初值
    double initial_x = 5.0;
    double x = initial_x;

    //2.构建寻优问题:定cost fun 和 添加优化参数
    ceres::Problem problem;
    ceres::CostFunction *cost_function =
            new ceres::AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor);//使用自动求导
    problem.AddResidualBlock(cost_function, NULL, &x);      //向问题中添加误差项，本问题比较简单，添加一个就行
    // loss fun针对单个样本,cost fun针对整个样本集合

    //3.配置和运行求解器
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;//配置增量方程的解法
    options.minimizer_progress_to_stdout = true;//输出到cout
    ceres::Solver::Summary summary;//report优化信息
    ceres::Solve(options, &problem, &summary);//求解

    //4.输出结果
    std::cout << summary.BriefReport() << endl;
    std::cout << "result x = " << x << endl;

    return 0;
}