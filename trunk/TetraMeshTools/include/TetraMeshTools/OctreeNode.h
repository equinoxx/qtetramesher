/**
 *	OctreeNode.h
 *
 *	Node implementation for the Octree.
 *
 *	Author: Dennis Luebke, 2013
 *
 */

#pragma once

#include <vector>
#include "TetraToolsExports.h"
#include "GeometryTypes.h"

struct PointQuadrant
{
	bool left;
	bool back;
	bool top;
	unsigned int result;
};

class DLL_EXPORT OctreeNode
{
private:
	const OctreeNode*			_parent;
	unsigned int				_depth; // current depth level of our octree
	static unsigned int			_maxDepth; // static int for maximum depth of our octree
	std::vector<OctreeNode*>	_nodes; // a maximum of 8 children is possible
	static std::vector<Vec3f>*	_points; // pointer to surface mesh points
	//std::vector<Vec3f*>			_pointsInSelf;	// list of point-pointers to know which surface points are contained in the current child
	Vec3f						_minBC, _maxBC;	// 3D points for opposite corners
	const int					_quadrant;
	
	void buildNode();

public:
	// only necessary for root node
	OctreeNode(const unsigned int maxDepth_, std::vector<Vec3f>* inPoints_, const Vec3f& _minBC, const Vec3f& _maxBC);
	// this constructor is only for the child nodes
	OctreeNode(const OctreeNode* parent_, const Vec3f& _minBC, const Vec3f& _maxBC, const unsigned int depth_, const int quadrant_);
	~OctreeNode();

	const OctreeNode* getParent() const;

	const std::vector<OctreeNode*>& getChildren() const;

	const Vec3f& getMinBC() const;

	const Vec3f& getMaxBC() const;

	void clear();

};
 