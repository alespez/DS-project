simple Coordinator {


}


simple MapperNode
{
    parameters:

    gates:

        input in; //mapIn
        output out; //mapOut
}


simple ReducerNode
{
    parameters:

    gates:

        input in; //reduceIn
}


network MapReduce
{
    parameters:
        int n = default(10);

    submodules:
        Map[n]: MapperNode;
        Red[n]: ReducerNode;

    connections:
        for i=0..n-1 {
            Map[i].out --> {delay = 100ms;} --> Red[i].in;
        }
}
