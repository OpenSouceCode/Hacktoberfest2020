const updateItemList = (list: Array<any>, item: any, action: 'ADD' | 'DELETE' | 'UPDATE' | 'PUT', key: any = 'id'): typeof list => {
        list = list || [];
        let newList = list.slice();
        let itemIndex;
        if (action === 'UPDATE') {
            itemIndex = newList.findIndex(listItem => item[key] === listItem[key]);
            if (itemIndex !== -1)
                newList.splice(itemIndex, 1, item);
            return newList;
        } else if (action === 'ADD') {
            newList.unshift(item);
            return newList;
        } else if (action === 'DELETE') {
            return newList.filter(listItem => item[key] !== listItem[key]);
        }
        else if (action === 'PUT') {
            itemIndex = newList.findIndex(listItem => item[key] === listItem[key]);
            if (itemIndex !== -1)
                newList.splice(itemIndex, 1, item);
            else {
                newList.push(item);
            }
            return newList;
        }
        return newList;
    }
