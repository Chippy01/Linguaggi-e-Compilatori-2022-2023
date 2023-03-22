#include "LocalOpts.h"
#include "llvm/IR/InstrTypes.h"
#include <string.h>

using namespace llvm;

bool runOnBasicBlock2(BasicBlock &B) {
    
    for (auto iter = B.begin(); iter != B.end(); ++iter){
      Instruction &inst = *iter;

      if (inst.getOpcode() == Instruction::Add) {
        ConstantInt *c = dyn_cast<ConstantInt>(inst.getOperand(1));
        if (c && c->getValue().isZero()){
          inst.replaceAllUsesWith(inst.getOperand(0));

        }


        
      }
    }
   

  return true;
}


  bool runOnFunction2(Function &F) {
    bool Transformed = false;

    for (auto Iter = F.begin(); Iter != F.end(); ++Iter) {
      if (runOnBasicBlock2(*Iter)) {
        Transformed = true;
      }
    }

    return Transformed;
  }




PreservedAnalyses AlgebricIdentityPass::run([[maybe_unused]] Module &M,
                                             ModuleAnalysisManager &) {

  // Un semplice passo di esempio di manipolazione della IR
  for (auto Iter = M.begin(); Iter != M.end(); ++Iter) {
    if (runOnFunction2(*Iter)) {
      return PreservedAnalyses::none();
    }
  }

  return PreservedAnalyses::none();
}

