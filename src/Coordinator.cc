#include <string.h>
#include <omnetpp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "OperationMessage_m.h"
using namespace omnetpp;

/**
 * Derive the Txc1 class from cSimpleModule. In the Tictoc1 network,
 * both the `tic' and `toc' modules are Txc1 objects, created by OMNeT++
 * at the beginning of the simulation.
 */
class Coordinator : public cSimpleModule
{
  const int key_value_generated= 2;
  const int num_of_partitions= 2;
  const int length_absolute_path=100;
  const char operationToPerform[20]="map";

  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void createPartitions(char absolutePath[100]);
    int checkLettersDrawn(char letterUsed[], char caracterDrawn);
    virtual void generateMessage(char partition[20],char operationToPerform[20],int nodeToSend);
};

// The module class needs to be registered with OMNeT++
Define_Module(Coordinator);

void Coordinator::initialize()
{
    char partitionLocations[num_of_partitions][length_absolute_path];
    char fileName[20] = "partition";
    char endOfTheName[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char charactersUsed[26];
    strncpy(charactersUsed, " ", sizeof(charactersUsed));

    for (int i = 0; i < num_of_partitions; i++)
    {
        char absolutePath[100];
        char letter;
        int seen = 0;
        do
        {
            int random = rand() % 25;
            letter = endOfTheName[random];
            int seen = checkLettersDrawn(charactersUsed, letter);
        } while (seen == 1);

        //  printf("caracther extracted %c\n", letter);
        sprintf(absolutePath, "C:\\Users\\spagn\\Desktop\\prova\\partition%c.txt", letter);
        strcpy(partitionLocations[i], absolutePath);
        //  printf("name of the file %s\n", absolutePath);
        createPartitions(absolutePath);

    }
/*
    for (int i=0;i<num_of_partitions;i++){
        printf("absolute path, %s\n",partitionLocations[i]);
    }
*/

}

void Coordinator::handleMessage(cMessage *msg)
{

}
void Coordinator::createPartitions(char absolutePath[100])
{
    FILE *fptr;
       fptr = fopen(absolutePath, "w");
       for (int i = 0; i < key_value_generated; i++)
       {
           int key = rand() % 20;
           int value = rand() % 20;
           char keyValuePair[20];
           sprintf(keyValuePair, "%d %d", key, value);
           fprintf(fptr, "%s\n", keyValuePair);
       }
       fclose(fptr);
}
int Coordinator::checkLettersDrawn(char letterUsed[], char caracterDrawn)
{
    int seen = 0;
    for (int i = 0; i < 26; i++)
    {
        if (strcmp(&letterUsed[i], " ") != 0)
        {
            if (strcmp(&letterUsed[i], &caracterDrawn))
            {
                seen = 1;
            }
        }
    }
    return seen;
}
void Coordinator::generateMessage(char partition[20],char operationToPerform[20],int nodeToSend)
{

}


