//#include <iostream>
//
//using namespace std;
//
//struct Node {
//    explicit Node(int64_t i) : left(nullptr), right(nullptr), parrent(nullptr),
//                               value(i), sum(i) {}
//
//    Node *left;
//    Node *right;
//    Node *parrent;
//    int64_t value;
//    int64_t sum;
//};
//
//
//class SplayTree {
// public:
//    void Insert(int64_t key);
//
//    void Remove(int64_t key);
//
//    bool Find(int64_t value);
//
//    int64_t GetSumm(int64_t k1, int64_t k2);
//
// private:
//    void Splay(Node *node);
//
//    void Zig(Node *node);
//
//    void Zag(Node *node);
//
//    void ZigZig(Node *node);
//
//    void ZigZag(Node *node);
//
//    void ZagZig(Node *node);
//
//    void ZagZag(Node *node);
//
//    void Merge(Node *v1, Node *v2);
//
//    Node *root = nullptr;
//};
//
//void SplayTree::Insert(int64_t key) {
//  if (root == nullptr) {
//    root = new Node(key);
//    return;
//  }
//  Node *current = root;
//  while (true) {
//    if (current->value == key) {
//      return;
//    }
//    if (current->value < key) {
//      if (current->right != nullptr) {
//        current = current->right;
//        continue;
//      } else {
//        current->right = new Node(key);
//        current->right->parrent = current;
//        current = current->right;
//        break;
//      }
//    }
//    if (current->value > key) {
//      if (current->left != nullptr) {
//        current = current->left;
//        continue;
//      } else {
//        current->left = new Node(key);
//        current->left->parrent = current;
//        current = current->left;
//        break;
//      }
//    }
//  }
//  Node *prev = current->parrent;
//  while (prev != nullptr) {
//    prev->sum += key;
//    prev = prev->parrent;
//  }
//  Splay(current);
//}
//
//bool SplayTree::Find(const int64_t value) {
//  if (root == nullptr) {
//    return false;
//  }
//  Node *current = root;
//  Node *prev;
//  while (current != nullptr && current->value != value) {
//    prev = current;
//    if (current->value < value) {
//      current = current->right;
//    } else {
//      current = current->left;
//    }
//  }
//  if (current == nullptr) {
//    Splay(prev);
//    return false;
//  } else {
//    Splay(current);
//    return true;
//  }
//}
//
//void SplayTree::Remove(int64_t key) {
//  if (Find(key)) {
//    if (root->left != nullptr) {
//      Node *c = root;
//      root->left->parrent = nullptr;
//      if (root->right != nullptr) {
//        root->right->parrent = nullptr;
//      }
//      root = root->left;
//      Merge(c->left, c->right);
//      c->left = nullptr;
//      c->right = nullptr;
//      delete c;
//    } else {
//      if (root->right != nullptr) {
//        root->right->parrent = nullptr;
//        Node *c = root->right;
//        root->right = nullptr;
//        delete root;
//        root = c;
//      } else {
//        delete root;
//        root = nullptr;
//      }
//    }
//  }
//}
//
//void SplayTree::Splay(Node *node) {
//  if (node == root) {
//    return;
//  }
//  if (node->parrent == root) {
//    if (root->right == node) {
//      Zag(node);
//      return;
//    } else {
//      Zig(node);
//      return;
//    }
//  }
//  Node *a = node->parrent, *b = node->parrent->parrent;
//  if (b->left == a) {
//    if (a->left == node) {
//      ZigZig(node);
//    } else {
//      ZagZig(node);
//    }
//  } else {
//    if (a->left == node) {
//      ZigZag(node);
//    } else {
//      ZagZag(node);
//    }
//  }
//  Splay(node);
//}
//
//
//void SplayTree::Zig(Node *node) {
//  node->parrent->left = node->right;
//  if (node->right != nullptr) {
//    node->right->parrent = node->parrent;
//  }
//  node->parrent->parrent = node;
//  node->right = node->parrent;
//  node->parrent = nullptr;
//  root = node;
//  node->sum += node->right->value;
//  if (node->right->right != nullptr) {
//    node->sum += node->right->right->sum;
//  }
//  node->right->sum -= node->value;
//  if (node->left != nullptr) {
//    node->right->sum -= node->left->sum;
//  }
//}
//
//void SplayTree::Zag(Node *node) {
//  node->parrent->right = node->left;
//  if (node->left != nullptr) {
//    node->left->parrent = node->parrent;
//  }
//  node->parrent->parrent = node;
//  node->left = node->parrent;
//  node->parrent = nullptr;
//  root = node;
//  node->sum += node->left->value;
//  if (node->left->left != nullptr) {
//    node->sum += node->left->left->sum;
//  }
//  node->left->sum -= node->value;
//  if (node->right != nullptr) {
//    node->left->sum -= node->right->sum;
//  }
//}
//
//void SplayTree::ZigZig(Node *node) {
//  Node *a = node->parrent;
//  node->parrent = a->parrent->parrent;
//  a->left = node->right;
//  if (node->right != nullptr) {
//    node->right->parrent = a;
//  }
//  node->right = a;
//  Node *b = a->parrent;
//  a->parrent = node;
//  b->left = a->right;
//  if (a->right != nullptr) {
//    a->right->parrent = b;
//  }
//  a->right = b;
//  b->parrent = a;
//  b->sum -= a->sum;
//  if (b->left != nullptr) {
//    b->sum += b->left->sum;
//  }
//  a->sum = b->sum + a->value;
//  if (a->left != nullptr) {
//    a->sum += a->left->sum;
//  }
//  node->sum = a->sum + node->value;
//  if (node->left != nullptr) {
//    node->sum += node->left->sum;
//  }
//  if (b == root) {
//    root = node;
//  } else {
//    if (node->value < node->parrent->value) {
//      node->parrent->left = node;
//    } else {
//      node->parrent->right = node;
//    }
//  }
//}
//
//void SplayTree::ZigZag(Node *node) {
//  Node *b = node->parrent, *a = b->parrent;
//  node->parrent = a->parrent;
//  a->parrent = node;
//  a->right = node->left;
//  if (node->left != nullptr) {
//    node->left->parrent = a;
//  }
//  node->left = a;
//  b->left = node->right;
//  if (node->right != nullptr) {
//    node->right->parrent = b;
//  }
//  node->right = b;
//  b->parrent = node;
//  b->sum -= node->value;
//  if (a->right != nullptr) {
//    b->sum -= a->right->sum;
//  }
//  a->sum -= b->sum;
//  a->sum -= node->value;
//  node->sum = node->value + a->sum + b->sum;
//  if (a == root) {
//    root = node;
//  } else {
//    if (node->value < node->parrent->value) {
//      node->parrent->left = node;
//    } else {
//      node->parrent->right = node;
//    }
//  }
//}
//
//void SplayTree::ZagZig(Node *node) {
//  Node *a = node->parrent, *b = a->parrent;
//  a->right = node->left;
//  if (node->left != nullptr) {
//    node->left->parrent = a;
//  }
//  b->left = node->right;
//  if (node->right != nullptr) {
//    node->right->parrent = b;
//  }
//  a->parrent = node;
//  node->parrent = b->parrent;
//  b->parrent = node;
//  node->right = b;
//  node->left = a;
//  b->sum -= a->sum;
//  if (b->left != nullptr) {
//    b->sum += b->left->sum;
//    a->sum -= b->left->sum;
//  }
//  a->sum -= node->value;
//  node->sum = a->sum + b->sum + node->value;
//  if (b == root) {
//    root = node;
//  } else {
//    if (node->value < node->parrent->value) {
//      node->parrent->left = node;
//    } else {
//      node->parrent->right = node;
//    }
//  }
//}
//
//void SplayTree::ZagZag(Node *node) {
//  Node *b = node->parrent, *a = b->parrent;
//  a->right = b->left;
//  if (b->left != nullptr) {
//    b->left->parrent = a;
//  }
//  node->parrent = a->parrent;
//  a->parrent = b;
//  b->left = a;
//  b->right = node->left;
//  if (node->left != nullptr) {
//    node->left->parrent = b;
//  }
//  b->parrent = node;
//  node->left = b;
//  a->sum -= b->sum;
//  if (a->right != nullptr) {
//    a->sum += a->right->sum;
//  }
//  b->sum = b->value + a->sum;
//  if (b->right != nullptr) {
//    b->sum += b->right->sum;
//    node->sum -= b->right->sum;
//  }
//  node->sum += b->sum;
//  if (a == root) {
//    root = node;
//  } else {
//    if (node->value < node->parrent->value) {
//      node->parrent->left = node;
//    } else {
//      node->parrent->right = node;
//    }
//  }
//}
//
//void SplayTree::Merge(Node *v1, Node *v2) {
//  while (v1->right != nullptr) {
//    v1 = v1->right;
//  }
//  Splay(v1);
//  v1->right = v2;
//  if (v2 != nullptr) {
//    v2->parrent = v1;
//  }
//  if (v2 != nullptr) {
//    v1->sum += v2->sum;
//  }
//}
//
//int64_t SplayTree::GetSumm(int64_t k1, int64_t k2) {
//  if (root == nullptr) {
//    return 0;
//  }
//  Find(k1);
//  int64_t sum = root->sum;
//  if (root->left != nullptr) {
//    sum -= root->left->sum;
//  }
//  if (root->value < k1) {
//    sum -= root->value;
//  }
//  Find(k2);
//  if (root->right != nullptr) {
//    sum -= root->right->sum;
//  }
//  if ( k2 < root->value) {
//    sum -= root->value;
//  }
//  return sum;
//}
//
//int main() {
//  std::iostream::sync_with_stdio(false);
//  cin.tie(nullptr);
//  cout.tie(nullptr);
//  SplayTree tree;
//  int n;
//  char c;
//  int64_t s = 0;
//  int64_t a, b;
//  cin >> n;
//  for (int i = 0; i < n; ++i) {
//    cin >> c >> a;
//    if (c == '+') {
//      a = (a % 1000000001) + (s % 1000000001);
//      a %= 1000000001;
//      tree.Insert(a);
//    }
//    if (c == '-') {
//      a = (a % 1000000001) + (s % 1000000001);
//      a %= 1000000001;
//      tree.Remove(a);
//    }
//    if (c == '?') {
//      a = (a % 1000000001) + (s % 1000000001);
//      a %= 1000000001;
//      if (tree.Find(a)) {
//        cout << "Found" << std::endl;
//      } else {
//        cout << "Not found" << std::endl;
//      }
//    }
//    if (c == 's') {
//      if (a == 0) {
//        a = 0;
//      }
//      cin >> b;
//      a = (a % 1000000001) + (s % 1000000001);
//      a %= 1000000001;
//      b = (b % 1000000001) + (s % 1000000001);
//      b %= 1000000001;
//      s = tree.GetSumm(a, b);
//      cout << s << std::endl;
//    }
//  }
//}
