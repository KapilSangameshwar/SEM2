temp = head;
		while (temp->next != head) {
			printf("%d->", temp->data);
			temp = temp->next;
		}