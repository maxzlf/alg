#ifndef LINK_H
#define LINK_H

snode *buildLink(unsigned int len);
void printLink(snode *link);
void deleteLink(snode *link);
snode *revsLink(snode *link);
snode *knode(snode *link, unsigned int k);

#endif