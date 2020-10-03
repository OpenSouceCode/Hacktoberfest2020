'''
A Web scrapper that do the following:
1 opens a browser
2 go to amazon
3 search for productSearch (see variable below)
4 write name's product and price on a excel
5 saves excel in same directory as this code

IMPORTANT: for proper usage, you must have geckodriver.exe (for firefox) or chromedriver.exe (for chrome) in same directory as code file

Created by Guilherme Umemura in september 2020

Libraries used: 
    selenium, for browser navigation
    xlwt, for excel manuseability
    
GitHub: https://github.com/Gumemura/Amazon_web_scrapper

Excel will be saved on the same directory as script

Developed in
    Spyder 4.1.5
    Anaconda 4.8.4
    Python 3.7.4 
'''

import time #for giving the script a little break
from selenium import webdriver 
from tkinter import *

from xlwt import Workbook #excel functions

url = 'https://www.amazon.com.br/'
productSearch = "iphone"

class amazon_scraper:
    def __init__(self, product):
        self.url = url #the site we are going to be scraping
        self.driver = webdriver.Firefox()
        self.driver.get(self.url)
    
        self.search_bar = 'twotabsearchtextbox' # search box id
        self.button_search = 'nav-input' # search button class
        self.product_div_class = 'a-size-base-plus' # product name div class
        self.price_class = 'a-price-whole' #whole price div class
        self.coin_class = 'a-price-fraction' #fraction price div class
        
        '''Creating a excel'''
        self.wb = Workbook()
        self.result_sheet = self.wb.add_sheet('Products')
        
        self.row = 1
        self.column_name = 0
        
        self.column_price = 1
        
        self.search_and_enter(product)
        self.time_break(2)
        self.grab_product_info()
    
    def search_and_enter(self, word = 'None'):
        '''
        Type desired word in search box then hits search
        
        :Args:
        word -> the word to be searched
        '''
        self.driver.find_element_by_id(self.search_bar).send_keys(word)
        
        '''
        Looking for the search's button
        '''
        for elem in self.driver.find_elements_by_class_name(self.button_search):
            if elem.get_attribute("type") == "submit":
                elem.click()
                break
    
    def grab_product_info(self):
        '''
        Find the product name and its price and write them on a excel

        '''
        
        '''Writing titles on the excel'''
        self.result_sheet.write(0, self.column_name, 'PRODUCT NAMES')
        self.result_sheet.write(0, self.column_price, 'PRICES')
        
        for elem in self.driver.find_elements_by_class_name(self.product_div_class):
            '''Finding mother div so we can search for price from here'''
            mother_div = elem.find_element_by_xpath('../../../..')
            
            self.result_sheet.write(self.row, self.column_name, elem.text)
            
            try:
                self.result_sheet.write(self.row, self.column_price, mother_div.find_element_by_class_name(self.price_class).text + "," + mother_div.find_element_by_class_name(self.coin_class).text)
            except:
                self.result_sheet.write(self.row, self.column_price,'')
                
            self.row += 1
            
        '''Closing and saving excel'''
        self.wb.save('Amazon scraping results.xls')

    def time_break(self, break_time):
        '''
        Gives the execution a break
        :Args:
        time -> amount of seconds the break will last
        '''
        time.sleep(break_time)

iphone_finder = amazon_scraper(productSearch)