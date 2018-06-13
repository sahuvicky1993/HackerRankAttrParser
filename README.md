# HackerRankAttrParser


We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:

</tag-name>
*************************
Example:
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
************************
The attributes are referenced as:

tag1~value  
tag1.tag2~name

sample I/p:
--------------------------------
4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
-------------------------------------

sample 0/p:
Name1
Not Found!
HelloWorld









