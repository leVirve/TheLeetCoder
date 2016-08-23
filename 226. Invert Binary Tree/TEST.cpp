#include "../framework/header.hpp"
#include "solution.hpp"


TEST_CASE( "Invert Binary Tree are tested", "[invertTree]" ) {
    Solution s;
    TreeNode *r;

    TreeNode root(4), node1(2), node2(7), node3(1), node4(3), node5(6);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node5;

    r = s.invertTree(&root);
    REQUIRE( r->left->val == 7 );
    REQUIRE( r->right->val == 2 );
    REQUIRE( r->left->left == nullptr );
    REQUIRE( r->left->right->val == 6 );
    REQUIRE( r->right->left->val == 3 );
    REQUIRE( r->right->right->val == 1 );

    TreeNode root2(1), node_l1(2), node_l2(3);
    root2.left = &node_l1;
    node_l1.left = &node_l2;

    r = s.invertTree(&root2);
    REQUIRE( r->val == 1 );
    REQUIRE( r->right->val == 2 );
    REQUIRE( r->right->right->val == 3 );

    r = s.invertTree(nullptr);
    REQUIRE( r == nullptr );
}
