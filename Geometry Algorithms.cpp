//To determine whether a point (x,y) lies inside a rectangle
//Coordinates A(ax,ay), B(bx,by) and D(dx,dy) of the rectangle are required

bool lies_in(int ax,int ay,int bx,int by,int dx,int dy, int x, int y)
{
    int bax = bx - ax;
    int bay = by - ay;
    int dax = dx - ax;
    int day = dy - ay;
    if ((x - ax) * bax + (y - ay) * bay < 0.0) 
        return false;
    if ((x - bx) * bax + (y - by) * bay > 0.0) 
        return false;
    if ((x - ax) * dax + (y - ay) * day < 0.0) 
        return false;
    if ((x - dx) * dax + (y - dy) * day > 0.0) 
        return false;
    return true;
}

//Find distance between two points (a,b) and (x,y)

float dist(int a, int b, int x, int y)
{
    float dist_x=pow(abs(x-a),2);
    float dist_y=pow(abs(y-b),2);
    return sqrt(dist_x+dist_y);
}

// Taken from https://github.com/Aksh77/ACM-Team-Notebook