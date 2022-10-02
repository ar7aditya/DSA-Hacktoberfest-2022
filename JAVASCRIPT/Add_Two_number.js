

function ListNode(val, next) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
  
  /**
   * @param {ListNode} l1
   * @param {ListNode} l2
   * @return {ListNode}
   */
  var addTwoNumbers = function (l1, l2) {
    let carry = 0;
    let additionNode = new ListNode(0);
    let ansNode = additionNode;
  
    while (l1 || l2 || carry) {
      let sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
      carry = Math.floor(sum / 10);
      sum %= 10;
      ansNode.next = new ListNode(sum);
  
      l1 = l1 ? l1.next : null;
      l2 = l2 ? l2.next : null;
      ansNode = ansNode.next;
    }
  
    return additionNode.next;
  };







