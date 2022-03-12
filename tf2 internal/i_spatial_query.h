#pragma once

// todo: remove when i add traceray.
struct ray_t;

class i_spatial_leaf_enumerator {
public:
	virtual bool enumerate_leaf( int leaf, int context ) = 0;
};

class i_spatial_query {
public:
	virtual int leaf_count( ) const = 0;
	virtual bool enumerate_leaves_at_point( vector const& pt, i_spatial_leaf_enumerator* p_enum, int context ) = 0;
	virtual bool enumerate_leaves_in_box( vector const& mins, vector const& maxs, i_spatial_leaf_enumerator* p_enum, int context ) = 0;
	virtual bool enumerate_leaves_in_sphere( vector const& center, float radius, i_spatial_leaf_enumerator* p_enum, int context ) = 0;
	virtual bool enumerate_leaves_along_ray( ray_t const& ray, i_spatial_leaf_enumerator* p_enum, int context ) = 0;
};