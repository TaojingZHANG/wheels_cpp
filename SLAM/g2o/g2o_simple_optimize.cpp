#include <iostream>
#include "g2o/core/sparse_optimizer.h"
#include "g2o/core/block_solver.h"
#include "g2o/core/factory.h"
#include "g2o/core/optimization_algorithm_levenberg.h"
#include "g2o/solvers/csparse/linear_solver_csparse.h"

#include "g2o/types/slam2d/vertex_se2.h"
#include "g2o/types/slam3d/vertex_se3.h"

//进行类型注册, 也就是optimizer.load 和optimizer.save 在执行时有相对的类型对应
// 保证能够进graph的load 和save
G2O_USE_TYPE_GROUP(slam3d);
G2O_USE_TYPE_GROUP(slam2d);

#include <iostream>

using namespace std;
using namespace g2o;

#define MAXITERATION 10

int main(int argc, char **argv) {
    //1.创建求解器



    BlockSolverX::LinearSolverType *linearSolver=
            new LinearSolverCSparse<BlockSolverX::PoseMatrixType>();
    BlockSolverX* blockSolverX = new BlockSolverX(linearSolver);





    return 1;
}