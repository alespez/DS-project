//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
simple Coordinator
{
    gates:
        input in[]; //mapIn
        output out[]; //mapOut
}


simple MapperNode
{
    gates:

        input in; //mapIn
        output out; //mapOut
}




network DistributedProject
{
    parameters:
        int n = default(10);

        @display("bgb=429,164");
    submodules:
        Map[n]: MapperNode {
            @display("p=51,76");
        }
        Cor: Coordinator {
            @display("p=244,101");
        }
    connections:

        for i=0..n-1 {
            Cor.out++ --> {  delay = 100ms; } --> Map[i].in;
			Map[i].out --> {  delay = 100ms; } --> Cor.in++;
        }
}
