

struct btree
{
	int data;
	struct btree *left;
	struct btree *right;
};

typedef struct btree NODE;

typedef struct btree
{
	int data;
	NODE *left;
	NODE *right;
}NODE;

NODE *START = NULL;



