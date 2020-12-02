#ifndef GRAPHDFS_H
#define GRAPHDFS_H
#include "team.h"

namespace unicorn{

class GraphDFS
{
    int V; // No. of vertices

    // Pointer to an array containing
    // adjacency lists
    list<Stadium> *adj;
    vector<Distance*> dfsPath; // store dfs path
    set<Distance*> allEdgs; // store all edges discover and back
    int totalDistance;
     stack <Distance*> visitedEdgesStack;


    // Mark all the vertices as not visited
    bool *visited ;

    // A recursive function used by DFS
    void DFSUtil(int v);
public:
    GraphDFS(int v); // Constructor
    int visitedVert();

    // function to add an edge to graph
    void addEdge(int v, Stadium& w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);

     QString printDFS();



   int getTotalEdgeType(){

        set<Distance*>::iterator ed;

                for (ed = allEdgs.begin(); ed != allEdgs.end(); ++ed)
                {
                    if((*ed)->Discovered )
                    {
                        totalDistance+= (*ed)->distance;
                    }

                }
               return  totalDistance;
    }



};



GraphDFS::GraphDFS(int v)
{
    //vect = vect_;
    this->V = v;
    adj = new list<Stadium>[V];
    visited = new bool[V];
    totalDistance =0;
    for (int i = 0; i < V; i++)
            visited[i] = false;
    visited[0] = true;
}



 QString GraphDFS::printDFS()
{

    QString str="<table cellpadding=\"5\" border=\"0\" cellspacing=\"5\" width=\"100%\" ><h3>DFS Traversal (Total Distance: "+QString::number(getTotalEdgeType())+" Miles) </h3>";
    vector<Distance*>::iterator it;
    int i=1;
    for(it= dfsPath.begin(); it!= dfsPath.end();++it)
    {
        if((*it)->StadiumID == (*it)->StartPoint )
        {
            str+="<tr><td style=\"border:solid 1px #000;width:50%\"><b>Stadium:</b> "+QString::fromStdString( (*it)->StadiumIDPtr->getStadiumName())+"<br/>"+(*it)->StadiumIDPtr->getTeamsName()+"</td><td style=\"text-align:center;valign:middle\">("+QString::number( (*it)->distance)+"M)<br/>&#8594;</td> <td style=\"border:solid 1px #000;width:50%\"><b>Stadium:</b> "+QString::fromStdString((*it)->OtherStaduimIDPtr->getStadiumName())+"<br/>"+(*it)->OtherStaduimIDPtr->getTeamsName()+"</td></tr>";
        }
        else
        {
            str+="<tr><td style=\"border:solid 1px #000;width:50%\"><b>Stadium:</b> "+QString::fromStdString( (*it)->OtherStaduimIDPtr->getStadiumName())+"<br/>"+(*it)->OtherStaduimIDPtr->getTeamsName()+"</td><td style=\"text-align:center;valign:middle\" >("+QString::number((*it)->distance)+"M)<br/>&#8594;</td> <td style=\"border:solid 1px #000;width:50%\"><b>Stadium:</b> "+QString::fromStdString((*it)->StadiumIDPtr->getStadiumName())+"<br/>"+(*it)->StadiumIDPtr->getTeamsName()+"</td></tr>";
        }



    i++;
    }
       str+="</table>";

    return  str;
}




int GraphDFS::visitedVert(){
    int count =0;
    for (int i = 0; i < V; i++)
    {
        if(visited[i]== true){count++;}
    }
    return count;
}

void GraphDFS::addEdge(int v, Stadium& w)
{
    adj[v].push_back(w); // Add w to v’s list.
}




void GraphDFS::DFSUtil(int v)
{


    list<Stadium>::iterator i;
   vector<Distance*>::iterator ed;
    int min=0;

    vector<Distance*> avEdges;
    vector<Distance*> dist;
    visited[v] = true;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {

            dist =  (*i).getDistanceFromOthers();

            for (auto ed = dist.begin(); ed != dist.end(); ++ed)
            {
                //cout<<"ididid" << (*ed)->StadiumID<<endl;

                if((*ed)->Discovered==false && (!visited[(*ed)->StadiumID] || !visited[(*ed)->OtherStaduimID] )&& ((*ed)->StadiumID == v || (*ed)->OtherStaduimID == v ) )
                {
                    allEdgs.insert(*ed);
                    avEdges.push_back(*ed);
                }
            }

        }
    // Mark the current node as visited and


    if(avEdges.size()>0)
    {
    // get minimum distance node


    auto minElem = min_element( avEdges.begin(), avEdges.end(), []( const Distance *a, const Distance *b ){ return a->distance < b->distance;});
    min = (*minElem)->distance;


    int minKey= (*minElem)->StadiumID == v ? (*minElem)->OtherStaduimID : (*minElem)->StadiumID;

       // cout<<"minkey===="<<minKey<<"-" << v <<endl;
        if (!visited[minKey] )
        {
           // cout<< (*minElem)->StadiumID;

            if(v== (*minElem)->StadiumID){
                (*minElem)->StartPoint = (*minElem)->StadiumID;
                (*minElem)->endPoint = (*minElem)->OtherStaduimID;
            }
            if(v== (*minElem)->OtherStaduimID){
                (*minElem)->StartPoint = (*minElem)->OtherStaduimID;
                (*minElem)->endPoint = (*minElem)->StadiumID;
            }


            dfsPath.push_back(*minElem);
            visitedEdgesStack.push(*minElem);

            (*minElem)->Discovered = true; // lable edge as discovery
            if(visitedVert()<V)
            {
                DFSUtil(minKey);
            }

        }
        else
        {
            if(visitedVert()<V && visitedEdgesStack.size()>0)
            {
                int std = visitedEdgesStack.top()->StadiumID;
                visitedEdgesStack.pop();

                 //cout<< "stack"<<visitedEdgesStack.size()<<endl;
                    DFSUtil(std);
            }
        }
    }
    else if(visitedVert()<V && visitedEdgesStack.size()>0)
    {
        //cout<< "stack"<<visitedEdgesStack.size();
        int std = visitedEdgesStack.top()->StadiumID;
        visitedEdgesStack.pop();
                DFSUtil(std);
    }

}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void GraphDFS::DFS(int v)
{

    // Call the recursive helper function
    // to print DFS traversal

    DFSUtil(v);
}

};
#endif // GRAPHDFS_H
