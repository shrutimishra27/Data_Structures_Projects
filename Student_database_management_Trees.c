#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct BSTnode {

   char student[51], meaning[251];

   struct BSTnode * left, * right;

};

struct BSTnode * root = NULL;

struct BSTnode *createNode(char * student, char * meaning) {

      struct BSTnode * newnode;
      newnode = (struct BSTnode * ) malloc(sizeof(struct BSTnode));
      strcpy(newnode -> student, student);
      strcpy(newnode -> meaning, meaning);
      newnode -> left = newnode -> right = NULL;
      return newnode;
   }

void insert(char * student, char * meaning) {

   struct BSTnode * parent = NULL, * current = NULL, * newnode = NULL;

   int res = 0;
   if (!root)
   {
      root = createNode(student, meaning);
      return;
   }

   for (current = root; current != NULL; current = (res > 0) ? current -> right : current -> left)
   {
      res = strcasecmp(student, current -> student);
      if (res == 0)
      {
         printf("The world has been already inserted in the database!\n");
         return;
      }
     parent = current;

   }

   newnode = createNode(student, meaning);
   res > 0 ? (parent -> right = newnode) : (parent -> left = newnode);
   return;
}

void findNode(char * str) {

   struct BSTnode * temp = NULL;
   int flag = 0, res = 0;
   if (root == NULL)
   {
      printf("The database is empty!\n");
      return;
   }

   temp = root;
   while (temp)
   {
      if ((res = strcasecmp(temp -> student, str)) == 0)
      {
         printf("student      : %s \n", str);
         printf("Rollno: %s \n", temp -> meaning);
         flag = 1;
         break;
      }
      temp = (res > 0) ? temp -> left : temp -> right;
   }

   if (!flag)
      printf("The student was not found in the database\n");
   return;
}

void inorderTraversal(struct BSTnode * myNode) {

   if (root== NULL)
   {
      printf("The database is empty!\n");
      return;
   }

   if (myNode)
   {
      inorderTraversal(myNode -> left);
      printf("student : %s", myNode -> student);
      printf("  -  %s", myNode -> meaning);
      printf("\n");
      inorderTraversal(myNode -> right);
   }

   return;

}

void deleteNode(char * str) {

   struct BSTnode * parent = NULL, * current = NULL, * temp = NULL;
   int flag = 0, res = 0;

   if (!root)
   {
      printf("The database is empty!\n");
      return;
   }
   current = root;

   while (1)
   {
      res = strcasecmp(current -> student, str);
      if (res == 0)
         break;
      flag = res;
      parent = current;
      current = (res > 0) ? current -> left : current -> right;
      if (current == NULL)
         return;
   }

   if (current -> right == NULL)
   {
      if (current == root && current -> left == NULL)
      {

         free(current);
         root = NULL;
         return;

      } 
      else if (current == root)
      {
         root = current -> left;
         free(current);
         return;
      }

      flag > 0 ? (parent -> left = current -> left) :
         (parent -> right = current -> left);

   } 
   else
   {

      temp = current -> right;
      if (!temp -> left)
      {

         temp -> left = current -> left;
         if (current == root)
         {
            root = temp;
            free(current);
            return;
         }

         flag > 0 ? (parent -> left = temp) : (parent -> right = temp);

      } 
      else
      {

         struct BSTnode * successor = NULL;
         while (1)
         {

            successor = temp -> left;
            if (!successor -> left)
               break;
            temp = successor;
         }

         temp -> left = successor -> right;
         successor -> left = current -> left;
         successor -> right = current -> right;
         
         if (current == root)
         {
            root = successor;
            free(current);
            return;
         }

         (flag > 0) ? (parent -> left = successor) : (parent -> right = successor);
      }
   }

   free(current);
   return;
}

void fileread() {

   char line[301], str[50], meaning[250];
   FILE * fread;
   fread = fopen("database.txt", "w+");
   if (access("database.txt", F_OK) != -1)
      while (fgets(line, 301, fread) != NULL)
   {

      char * del;

      del = strtok(line, "[");

      sprintf(str, "%s", del);

      del = strtok(NULL, "]");

      sprintf(meaning, "%s", del);

      insert(str, meaning);

   }

   fclose(fread);

   return;

}

void filesave(struct BSTnode * myNode) {

   FILE * fwrite;

   fwrite = fopen("database.txt", "a");

   if (myNode)

   {

      filesave(myNode -> left);

      fprintf(fwrite, "%s[", myNode -> student);

      fprintf(fwrite, "%s]", myNode -> meaning);

      fprintf(fwrite, "\n");

      filesave(myNode -> right);

   }

   fclose(fwrite);

   return;

}

void clearfile() {

   FILE * fsave;

   fsave = fopen("database.txt", "w");

   fclose(fsave);

   return;

}

int main() {

   fileread();

   int ch;

   char student[50], meaning[250];

   printf("SIMPLE BST database\n");

   while (1)

   {

      printf("-----------------------");

      printf
         ("\n1. Insert node\n2. Delete node\n3. Search node\n4. Alphabetical order\n5. Save and quit\nChoose your option:");

      scanf("%d", & ch);

      getchar();

      switch (ch)

      {

      case 1:

         printf("The student:");

         fgets(student, 50, stdin);

         student[strcspn(student, "\n")] = 0;

         printf("The rollno:");

         fgets(meaning, 250, stdin);

         meaning[strcspn(meaning, "\n")] = 0;

         insert(student, meaning);

         break;

      case 2:

         printf("Type the student that is going to be deleted:");

         scanf("%s", student);

         deleteNode(student);

         break;

      case 3:

         printf("Type the student that is going to be searched:");

         scanf("%s", student);

         findNode(student);

         break;

      case 4:

         inorderTraversal(root);

         break;

      case 5:

         clearfile();

         filesave(root);

         exit(0);

      default:

         printf("The option is not available\n");

         break;

      }

   }
   return 0;
}