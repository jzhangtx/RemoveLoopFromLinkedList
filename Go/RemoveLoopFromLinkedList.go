package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) (*ListNode, *ListNode) {
	if len(v) == 0 {
		return nil, nil
	}

	if len(v) == 1 {
		pNode := &ListNode{v[0], nil}
		return pNode, pNode
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead, pCur
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
	}
	if pNode.next != nil {
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func GetNodeByIndex(pHead *ListNode, index int) *ListNode {
	if index == -1 {
		return nil
	}

	for i := 0; i < index; i++ {
		pHead = pHead.next
	}

	return pHead
}

func GetStartingNodeOfLoop(list *ListNode) *ListNode {
	checked := make(map[*ListNode]struct{})
	for ; list != nil; list = list.next {
		_, exists := checked[list]
		if exists {
			return list
		}
		checked[list] = struct{}{}
	}

	return nil
}

func RemoveLoop(list *ListNode) {
	pNode := GetStartingNodeOfLoop(list)
	if pNode == nil {
		return
	}

	p := pNode
	for {
		if p.next == pNode {
			p.next = nil
			break
		}

		p = p.next
	}
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the list: ")
		pHead, pTail := GetListFromArray(vec)

		fmt.Print("The node index the loop start with: ")
		var m int
		fmt.Scan(&m)

		pTail.next = GetNodeByIndex(pHead, m)

		RemoveLoop(pHead)

		fmt.Print("After loop removed, the list is ")
		pHead.Print()
	}
}
