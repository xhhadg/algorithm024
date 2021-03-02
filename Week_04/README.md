深度优先 广度优先遍历，贪心，二分查找
=====================================

纯粹套用模板，必须记忆到形成条件反射
# BFS代码模板

* Python
```python
    def BFS(graph, start, end):    
        visited = set()	
        queue = [] 	
        queue.append([start]) 
		
        while queue: 		
            node = queue.pop() 		
            visited.add(node)	

            process(node) 		
            nodes = generate_related_nodes(node) 		
            queue.push(nodes)	
		
        # other processing work 	...
```
* // C/C++
```cpp
	void bfs(Node* root) {  
		map<int, int> visited;  
		if(!root) return ;  
		
		queue<Node*> queueNode;  
		queueNode.push(root);  
		
		while (!queueNode.empty()) {    
			Node* node = queueNode.top();    
			queueNode.pop();   
			if (visited.count(node->val)) continue;    
			visited[node->val] = 1;   
			
			for (int i = 0; i < node->children.size(); ++i) {        
				queueNode.push(node->children[i]);   
			}  
		}  
		
		return ;
	}
```
# DFS代码模板

* Python 递归写法:
```python
    visited = set() 
    def dfs(node, visited):   
        if node in visited: # terminator    	
			# already visited     	
			return 	
			
        visited.add(node) 
         
        # process current node here. 	
		...	
		
        for next_node in node.children(): 		
            if next_node not in visited: 			
                dfs(next_node, visited)
```
* //C++ 递归写法：
```cpp
	map<int, int> visited;
	void dfs(Node* root) {  
		// terminator  
		if (!root) return ;  

		if (visited.count(root->val)) {  
			// already visited   
			return ; 
		}  
		visited[root->val] = 1;
		
		// process current node here.   
		// ...  
		for (int i = 0; i < root->children.size(); ++i) {   
			dfs(root->children[i]); 
		}  
		return ;
	}
```
* Python 非递归写法
```python
    def DFS(self, tree): 	
        if tree.root is None: 		
            return []

        visited, stack = [], [tree.root]
        	
        while stack: 		
            node = stack.pop() 		
            visited.add(node)		
            
            process (node) 		
            nodes = generate_related_nodes(node) 		
            stack.push(nodes) 
        
        # other processing work 	
        ...
```
* //C++ 非递归写法：
```cpp
	void dfs(Node* root) {  
		map<int, int> visited;  
		if(!root) return ;  
		
		stack<Node*> stackNode;  
		stackNode.push(root);  
		
		while (!stackNode.empty()) {    
			Node* node = stackNode.top();    
			stackNode.pop();    
			if (visited.count(node->val)) continue;    
			visited[node->val] = 1;    
			
			for (int i = node->children.size() - 1; i >= 0; --i) {        
				stackNode.push(node->children[i]);   
			}  
		}  

		return ;
	}
```
# 贪心算法
	不会回溯，只能向前；动态规划需要保存之前的结果进行回溯，或分支处理。

# 二分查找 
	直接人肉记忆 使用二分查找的基本条件：单调性，存在上下界，能通过索引访问
```cpp
int binarySearch(const vector<int>& nums, int target) {  
	int left = 0, right = (int)nums.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}
```

# 思考题
	使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方 找到分界线处的索引。(网上借鉴的，回头看完了自己写几遍)
```cpp
int findMin(vector<int>& nums) {//找最小元素下标
    int low = 0;
    int high = nums.size() - 1;
    int min_num = nums[low];
    int min_index = low;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] > nums[low]) {//左半部分有序
            if (min_num < nums[low]) {
                min_index = low;
                min_num = nums[low];
            }
            low = mid + 1;
        }
        else if (nums[mid] < nums[low]){//右半部分有序
            if (min_num < nums[mid]) {
                min_index = mid;
                min_num = nums[mid];
            }
            high = mid - 1;
        }
        else {//此时，只剩nums[low]和nums[high]未比较
            if (min_num < nums[low]) {
                min_index = low;
                min_num = nums[low];
            }
            if (min_num < nums[high]) {
                min_index = high;
                min_num = nums[high];
            }
            break;
        }
    }
    return min_index;
    }
```