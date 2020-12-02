#ifndef GRAPHBFS_H
#define GRAPHBFS_H
#include "team.h"
namespace unicorn{
class GraphBFS {

public:

    /**
     * @brief Default constructor
     */
    GraphBFS(int v);

    /**
     * @brief Function to add edge between 2 vertices
     * @param src: first vertex
     * @param dest: second vertex
     * @param nodeSrc: first vertex object
     * @param nodeDest: second  vertex object
     */
    void addEdge(int src, int dest, Stadium& nodeSrc, Stadium& nodeDest );
    /**
     * @brief function to perform BFS
     * @param start: starting vertex
     */
    void BFS(int start);

    /**
     * @brief function to display total distance
     * @return distance: integer
     */
    int getTotalDistance(){
        cout<<endl;
        cout<<"Total distance BFS: "<< totalDistance<<endl;
        return totalDistance;
    }

    /**
     * @brief function to print BFS Path
     * @return text: QString
     */
    QString printBFS();


    /**
     * @brief function to print BFS Path
     */
    void printBFS2();

    /**
     * @brief function to get total of path
     * @return total: integer
     */
    int getTotalEdgeType();

private:
    // Number of vertex
    int v;

    vector<Distance*> bfsPath; // store pfs path
    set<Distance*> allEdgs; // store all edges discover and back
    int totalDistance;

    // Adjacency matrix
    Stadium ** adj;
    // Mark all the vertices as not visited
    bool *visited ;


};

void GraphBFS::printBFS2()
{
   // cout<< "----BFS using adjacency matrix----"<<endl;
    QString str="";
    vector<Distance*>::iterator it;
    int i=1;
    for(it= bfsPath.begin(); it!= bfsPath.end();++it)
    {
        if((*it)->StadiumID == (*it)->StartPoint )
        {
            cout<< i << (*it)->StadiumIDPtr->getStadiumName()<<"->"<< (*it)->OtherStaduimIDPtr->getStadiumName() <<"("<< (*it)->distance<< ")"<<endl ;
        }
        else
        {
            cout<< i <<(*it)->OtherStaduimIDPtr->getStadiumName()<<"->"<< (*it)->StadiumIDPtr->getStadiumName() <<"("<< (*it)->distance<< ")"<<endl ;
        }
    i++;


    }
}


int GraphBFS::getTotalEdgeType(){
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

QString GraphBFS::printBFS()
{

    vector<Distance*>::iterator it;
    QString str="<table  cellpadding=\"5\" border=\"0\" cellspacing=\"5\"  width=\"100%\" style=\"table-layout:fixed;\" ><h3>BFS Traversal (Total Distance: "+QString::number(getTotalEdgeType())+" Miles) </h3>";

    int i=1;
    for(it= bfsPath.begin(); it!= bfsPath.end();++it)
    {
        if((*it)->StadiumID == (*it)->StartPoint )
        {
            str+="<tr><td style=\"border:solid 1px #666;width:50%\"><b>Stadium:</b> "+QString::fromStdString( (*it)->StadiumIDPtr->getStadiumName())+"<br/>"+(*it)->StadiumIDPtr->getTeamsName()+"</td><td style=\"text-align:center;valign:middle\">("+QString::number( (*it)->distance)+"M)<br/>&#8594;</td> <td style=\"border:solid 1px #666;width:50%\"><b>Stadium:</b> "+QString::fromStdString((*it)->OtherStaduimIDPtr->getStadiumName())+"<br/>"+(*it)->OtherStaduimIDPtr->getTeamsName()+"</td></tr>";
        }
        else
        {
            str+="<tr><td style=\"border:solid 1px #666;width:50%\"><b>Stadium:</b> "+QString::fromStdString( (*it)->OtherStaduimIDPtr->getStadiumName())+"<br/>"+(*it)->OtherStaduimIDPtr->getTeamsName()+"</td><td style=\"text-align:center;valign:middle\" >("+QString::number((*it)->distance)+"M)<br/>&#8594;</td> <td style=\"border:solid 1px #000;width:50%\"><b>Stadium:</b> "+QString::fromStdString((*it)->StadiumIDPtr->getStadiumName())+"<br/>"+(*it)->StadiumIDPtr->getTeamsName()+"</td></tr>";
        }

    i++;
    }
       str+="</table>";

    return  str;

}

// Function to fill the empty adjacency matrix
GraphBFS::GraphBFS(int v)
{
    this->v = v;

    adj = new Stadium*[v];
    for (int row = 0; row < v; row++) {
        adj[row] = new Stadium[v]();

        visited = new bool[v];
        totalDistance =0;
        for (int i = 0; i < v; i++)
                visited[i] = false;
    }
}




// Function to add an edge to the graph
void GraphBFS::addEdge(int src, int dest, Stadium& nodeSrc, Stadium& nodeDest )
{

    // Considering a bidirectional edge
    adj[src-1][dest-1] = nodeDest;
    adj[dest-1][src-1] = nodeSrc;
    // diagonal
    adj[src-1][src-1] = nodeSrc;
    adj[dest-1][dest-1] = nodeDest;

    vector<Distance*>::iterator ed;
//    dist =  (*i).getDistanceFromOthers();

//    for (auto ed = dist.begin(); ed != dist.end(); ++ed)
//    {

//    }
    vector <Distance*>dist = nodeSrc.getDistanceFromOthers();

    for (auto ed = dist.begin(); ed != dist.end(); ++ed)
    {
        allEdgs.insert(*ed);
    }
    dist.clear();
    dist = nodeDest.getDistanceFromOthers();

    for (ed = dist.begin(); ed != dist.end(); ++ed)
    {
        allEdgs.insert(*ed);
    }


}



// Function to perform BFS on the graph
void GraphBFS::BFS(int start)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning

    vector<Stadium> q;
    q.push_back(adj[start-1][start-1]);
   // bfsPath.push_back(adj[start][start]);

    // Set source as visited
    visited[start-1] = true;

    vector<Distance*> avEdges;
    int vis;
    vector <Distance*>dist;
    while (!q.empty()) {
        avEdges.clear();
        vis = q[0].getStadiumId();
        q.erase(q.begin());


        // For every adjacent vertex to the current vertex
        for (int i = 0; i < v; i++) {
            if(vis-1!=i)
            {
                dist.clear();
                dist = adj[vis-1][i].getDistanceFromOthers();
                for (auto ed = dist.begin(); ed != dist.end(); ++ed)
                {
                    if((*ed)->Discovered==false && (!visited[(*ed)->StadiumID-1] || !visited[(*ed)->OtherStaduimID-1] )&& ((*ed)->StadiumID == vis || (*ed)->OtherStaduimID == vis) )
                    {
                        avEdges.push_back(*ed);
                        (*ed)->StartPoint= vis;
                        (*ed)->endPoint= i+1;
                    }

                }

            }

        }

        if(avEdges.size()>0)
        {
            //cout<<avEdges.size()<<endl;
        // get minimum distance node
        sort( avEdges.begin(), avEdges.end(),
                                          []( const Distance *a, const Distance *b ){ return a->distance < b->distance;});
            for (auto ed = avEdges.begin(); ed != avEdges.end(); ++ed)
            {
                bfsPath.push_back(*ed);
                (*ed)->Discovered= true;
                q.push_back(adj[(*ed)->endPoint-1][(*ed)->endPoint-1]);
                visited[(*ed)->endPoint-1] = true;
            }
        }


    }

}



};
#endif // GRAPHBFS_H
