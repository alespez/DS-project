/*
 * mapperNode.cc
 *
 *  Created on: 9 apr 2023
 *      Author: spagn
 */

#include <string.h>
#include <omnetpp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace omnetpp;

/**
 * Derive the Txc1 class from cSimpleModule. In the Tictoc1 network,
 * both the `tic' and `toc' modules are Txc1 objects, created by OMNeT++
 * at the beginning of the simulation.
 */
class MapperNode : public cSimpleModule
{

  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void createPartitions(char absolutePath[100]);
    int checkLettersDrawn(char letterUsed[], char caracterDrawn);
};

// The module class needs to be registered with OMNeT++
Define_Module(MapperNode);

void MapperNode::initialize()
{


}

void MapperNode::handleMessage(cMessage *msg)
{

}
