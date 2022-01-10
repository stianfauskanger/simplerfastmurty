const createSfmModule = require("./sfmlib");
const sfmModule = createSfmModule();
const getSfmModule = async () => await sfmModule;

const logExampleProblemAndSolution = async () => {
    const sfmModule = await getSfmModule();
    const rawData = [
        -1001, 1000, 1000,
        1000, -1001, 1000,
        -1001, -1001, 1000,
    ];
    const data = new sfmModule.VectorOfDouble();
    rawData.forEach(i => data.push_back(i));
    const problem = new sfmModule.ProblemClass(data, 3, 3, 7);
    console.log("problem: ", problem.toString());
    console.log("problem.getData: ", problem.getData());
    console.log("problem.getData.size: ", problem.getData().size());
    console.log("problem.getData[0]: ", problem.getData().get(0));
    console.log("problem.getData[1]: ", problem.getData().get(1));
    console.log("problem.getData[2]: ", problem.getData().get(2));
    console.log("problem.getData[3]: ", problem.getData().get(3));
    console.log("problem.getN: ", problem.getN());
    console.log("problem.getM: ", problem.getM());
    console.log("problem.getMaxNumberOfSolutions: ", problem.getMaxNumberOfSolutions());

    var result = sfmModule.SolverClass.solve(problem);
    console.log("result.toFullString(): ", result.toFullString());
    console.log("result.getSolutions.size: ", result.getSolutions().size());
    console.log("result.getCosts.size: ", result.getCosts().size());
    for (let i = 0; i < result.getCosts().size(); i++) {
        const cost = result.getCosts().get(i);
        console.log("result.getCosts[" + i + "]: ", cost);
    }
    console.log("result.isError: ", result.isError());
};

module.exports = {
    getSfmModule,
    logExampleProblemAndSolution
};
