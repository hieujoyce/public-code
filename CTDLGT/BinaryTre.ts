class NodeTree {
    private data: number;
    private left: NodeTree;
    private right: NodeTree;

    constructor(data: number, left?: NodeTree, right?: NodeTree) {
        this.data = data;
        if (left && right) {
            this.left = left;
            this.right = right;
        } else {
            left = right = null;
        }
    }

    public getData(): number {
        return this.data;
    }

    public setData(data: number): void {
        this.data = data;
    }

    public getLeft(): NodeTree {
        return this.left;
    }

    public setLeft(left: NodeTree): void {
        this.left = left;
    }

    public getRight(): NodeTree {
        return this.right;
    }

    public setRight(right: NodeTree): void {
        this.right = right;
    }

    public toString(): string {
        return `${this.data}`;
    }
}

class BinaryTree {
    private length: number;
    private root: NodeTree;

    constructor(data?: number) {
        if (data !== null && data !== undefined) {
            let newNode = new NodeTree(data);
            this.root = newNode;
            this.length = 1;
        } else {
            this.length = 0;
            this.root = null;
        }
    }

    public getHeight() {}

    public size(): number {
        return this.length;
    }

    public isEmpty(): boolean {
        return this.length == 0;
    }

    public add(data: number) {
        if (this.root === null) {
            this.root = new NodeTree(data);
            return;
        }
        let currentNode = this.root;
        while (currentNode !== null) {
            if (data > currentNode.getData()) {
                currentNode = currentNode.getRight();
            } else {
                currentNode = currentNode.getLeft();
            }
        }
    }

    public remove() {}

    public toString(): string {
        return `${this.root.getData()}`;
    }
}

(function test() {
    let a = new BinaryTree();
    a.add(66);
    console.log(a.toString());
})();
