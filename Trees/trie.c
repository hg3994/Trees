#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHA_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')

typedef struct trie_node{
	int value; //used to mark leaf nodes
	struct trie_node *children[ALPHA_SIZE];
}trie_node;

typedef struct trie_t{
	trie_node *root;
	int count;
}trie_t;

// Returns new trie node (initialized to NULLs)
trie_node* getNode(void){
	trie_node *pNode=NULL;
	pNode=(trie_node *) malloc(sizeof(trie_node));
	if(pNode){
		int i;
		pNode->value=0;
		for(i=0;i<ALPHA_SIZE;i++)
			pNode->children[i]=NULL;
	}
	return pNode;
}

// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie){
	pTrie->root=getNode();
	pTrie->count=0;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(trie_t *pTrie,char key[]){
	int level;
	int length= strlen(key);// length 3 for "the"
	int index;
	trie_node *pCrawl; //make a temporary trie node

	pTrie->count++;
	pCrawl= pTrie->root; //and start it from the root
	for(level=0; level<length; level++){ //need to search for 't','h'&'e'

		index= CHAR_TO_INDEX(key[level]); //index of 't','h' &'e' between 0-25

		if( pCrawl->children[index]==NULL) //If key is not found, a new node is to be made
			 pCrawl->children[index]=getNode(); //it contsains the address of a node it is pointing to

		pCrawl= pCrawl->children[index]; // in the loop if it satisfies then we need to check for the next character 

		/*after "the", we are making an extra trie node, so that if "there" comes then 'e' would point to a trie node and 'r' woould be stored there. We are doing this intentionally as in the last line of searching algorithm, we are returning non-zero value if there exists a node after it and it has a value(it is a leaf node).*/
	}
	
	pCrawl->value= pTrie->count; //marking the leaf node
}

int search(trie_t *pTrie,char key[]){
	int level;
	int length= strlen(key);
	int index;
	trie_node *pCrawl;
	
	pCrawl=pTrie->root;
	for(level=0; level<length; level++){
		index= CHAR_TO_INDEX(key[level]);
		if(pCrawl->children[index]==NULL)
			return 0;
		pCrawl=pCrawl->children[index];
	}
	
	return (0 != pCrawl && pCrawl->value);
}

int main(){
	int i;
	char keys[][8]={"the", "a", "there", "answer", "any", "by", "bye", "their"};
	trie_t trie; //creation of a trie

	char output[][20]={"Not present in trie", "Present in trie"} ;
	
	initialize(&trie);

	//constructing a trie
	for(i=0;i<ARRAY_SIZE(keys);i++){
		insert(&trie,keys[i]);
	}
	
	//dict(&trie,key[0]);
	
	//Searching for different keys
	printf("%s --- %s\n", "the", output[search(&trie, "the")] );
	printf("%s --- %s\n", "there", output[search(&trie, "there")] );
	printf("%s --- %s\n", "their", output[search(&trie, "their")] );
	printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );

	return 0;
}
