import java.util.*;

abstract class HuffmanTree implements Comparable<HuffmanTree> 
{
	public final int frequency;
	public HuffmanTree(int frequency)
	{
		this.frequency = frequency;
	}

	public int compareTo(HuffmanTree tree)
	{
		return this.frequency - tree.frequency;
	}
}

class HuffmanLeaf extends HuffmanTree 
{
	public final char value;
	public HuffmanLeaf(int frequency, char value)
	{
		super(frequency);
		this.value = value;
	}
}

class HuffmanNode extends HuffmanTree 
{
	public final HuffmanTree left, right;

	public HuffmanNode(HuffmanTree left, HuffmanTree right)
	{
		super(left.frequency + right.frequency);
		this.left = left;
		this.right = right;
	}
}

public class HuffmanCode
{
	public static HuffmanTree buildTree(int[] charFreqs)
	{
		PriorityQueue<HuffmanTree> trees = new PriorityQueue<HuffmanTree>();

		for(int i = 0; i < charFreqs.length; i++)
			if(charFreqs[i] > 0)
				trees.offer(new HuffmanLeaf(charFreqs[i], (char)i));

		while(trees.size() > 1)
		{
			HuffmanTree a = trees.poll();
			HuffmanTree b = trees.poll();
			trees.offer(new HuffmanNode(a, b));
		}
		return trees.poll();
	}

	public static void printCodes(HuffmanTree tree, StringBuffer prefix, HashMap<char, StringBuffer> map)
	{
		assert tree != null;
		if(tree instanceof HuffmanLeaf)
		{
			HuffmanLeaf leaf = (HuffmanLeaf) tree;
			System.out.println(leaf.value + "\t" + prefix);
			map.put(leaf.value, prefix);
			return;
		}
		HuffmanNode node = (HuffmanNode) tree;

		prefix.append('0');
		printCodes(node.left, prefix);
		prefix.deleteCharAt(prefix.length()-1);

		prefix.append('1');
		printCodes(node.right, prefix);
		prefix.deleteCharAt(prefix.length()-1);
	}

	public static void main(String arg[])
	{
		String test = "this is a test";
		HashMap<char, StringBuffer> map;
		int[] charFreqs = new int[256];

		for(char c : test.toCharArray())
			charFreqs[c]++;

		HuffmanTree tree = buildTree(charFreqs);
		printCodes(tree, new StringBuffer());
	}
}
