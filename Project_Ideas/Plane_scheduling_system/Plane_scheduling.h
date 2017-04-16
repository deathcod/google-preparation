#include <bits/stdc++>.h
using namespace std;

class node
{
	String plane_number;
	int time_to_land;
public:
	node();
	~node();
	
};

class Plane_scheduling
{
	node * parent;
public:
	Plane_scheduling();
	~Plane_scheduling();

	// insert plane data such that it doesnot effect other plane landing or takeoff
	void insert();

	// delete the node if the landing or the takeoff is complete.
	void delete();

	// get the number of the planes about to land before a certain time T.
	int count_landing(int T);

private:

	// get the plane which is scheduled just before the current plane.
	node * before_this(node *x);

	// get the plane which is scheduled just after the current plane.
	node * after_this(node *x);

	// returns the latest flight which is about to land or takeoff
	node * find_min();

	// find if any plane exists within the  time interval the current plane enquires
	node * find(int time);
	

	// to get the parent node. 
	ndoe * get_parent(node *x);

};