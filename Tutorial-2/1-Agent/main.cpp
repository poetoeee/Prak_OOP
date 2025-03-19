#include "Agent.hpp"
#include "SuperAgent.hpp"

void setIDD(Agent *A){
    A->setID(1337);
}

int main() {
    SuperAgent agentX;
    Agent A;
    setIDD(&agentX);
    
    agentX.setID(9999);
    agentX.print();
    return 0;
}