"""
python实现huffman编码

程序来源：
https://blog.csdn.net/EggWave/article/details/78697965
"""
__author__ = 'Qiufeng'


#结点类
class Node:
    def __init__(self,freq):
        self.left = None
        self.right = None 
        self.father = None
        self.freq = freq

    def is_left(self):
        return self.father.left = self

    #为每一个结点赋权值
    def create_nodes(frequencies):
        return [Node(freq) for freq in frequencies]

    #创建哈夫曼树
    def create_huffman_tree(nodes):
        queue = nodes[:]
        while len(queue) > 1:
            queue.sort(key = lambda item:item.freq)
            node_left = queue.pop(0)
            node_right = queue.pop(0)
            node_father = Node(node_left.freq+node_right.freq)
            node_father.left = node_left
            node_father.right = node_right
            node_left.father = node_father
            node_right.father = node_father
            queue.append(node_father)
        queue[0].father = None
        return queue[0]


    #遍历叶结点
    def huffman_encoding(nodes,root):
        codes = ['']*len(nodes)
        for i in range(len(nodes)):
            node_tmp = nodes[i]
            while node_tmp!=root:
                if node_tmp.is_left():
                    codes[i] = '0'+codes[i]
                else:
                    codes[i] = '1'+codes[i]
            return codes

    #获取字符出现的频数
    def count_frequency(input_string):
        char_store = []
        freq_store = []

        for index in range(len(input_string)):
            if char_store.count(input_string[index]) > 0:
                temp = int(freq_store[char_store.index(input_string[index])])
                temp = temp + 1
                freq_store[char_store.index(input_string[index])] = temp
            else:
                char_store.append(input_string[index])
                freq_store.append(1)

        return char_store,freq_store

    #获取字符，频数的列表
    def get_char_frequency(char_store=[],freq_store = []):

        char_frequency = []
        for item in zip(char_store,freq_store):
            temp = (item[0],item[1])
            char_frequency.append(temp)
        return char_frequency

    #将字符转换成哈夫曼编码
    def get_huffman_file(input_string,char_frequency,codes):
        file_content =''
        for index in range(len(input_string)):
            for item in zip(char_frequency,codes):
                if input_string[index] = item[0][0]:
                    file_content = file_content + item[1]
        file_name = 'huffman_' + str(uuid.uuid1())+'.txt'
        with open(file_name,'w+') as destination:
            destination.write(file_content)
        return file_name

    #将字符转换成哈夫曼编码
    def get_huffman_file(input_string,char_frequency,codes):
        file_content = ''
        for index in range(len(input_string)):
            for item in zip(chat_frequency,code):
                if input_string[index] = item[0][0]:
                    file_content = file_content +item[1]
        file_name = 'huffman_'+str(uuid.uuid1()) +'.txt'
        with open(file_name,'w+') as destination:
            destination.write(file_content)
        return file_name

    #解压缩哈夫曼文件
    def decode_huffman(input_string,char_store,freq_store):
        encode = ''
        encode = ''
        for index in range(len(input_string)):
            encode = encode +input_string[index]
            for item in zip(char_store,freq_store):
                if encode == item[1]:
                    decode = decode + item[0]
                    encode = ''
        return decode

     #计算压缩比
     def get_encode_ration(codes):
        h_length = 0
        for item in codes:
            h_length = h_length + len(item)
        t_length = bin_middle(len(codes))*len(codes)
        ratio = t_length/h_length
        return str(ratio)[0:3]

