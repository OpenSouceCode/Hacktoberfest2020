from selenium import webdriver
from time import sleep

# driver = webdriver.Chrome() - For sampling testing purpose
# driver.get("https://www.google.com")
# print (driver.title)
# print (driver.current_url)
# driver.quit() 

class InstaBot:
    def __init__(self, username, pw):
        self.driver = webdriver.Chrome()
        self.username = username
        self.driver.get("https://instagram.com")
        sleep(2)
   
        self.driver.find_element_by_xpath("//input[@name=\"username\"]")\
            .send_keys(username)
        self.driver.find_element_by_xpath("//input[@name=\"password\"]")\
            .send_keys(pw)
        self.driver.find_element_by_xpath('//button[@type="submit"]')\
            .click()
        sleep(4)
        self.driver.find_element_by_xpath("//button[contains(text(), 'Not Now')]")\
            .click()
        sleep(2)

    def get_unfollowers(self):
        self.driver.find_element_by_xpath("/html/body/div[1]/section/main/section/div[3]/div[1]/div/div[2]/div[1]/a")\
            .click()
        sleep(5)
        self.driver.find_element_by_xpath("/html/body/div[1]/section/main/div/header/section/ul/li[3]/a")\
            .click()    
        following = self._get_names()
        self.driver.find_element_by_xpath("/html/body/div[1]/section/main/div/header/section/ul/li[2]/a")\
            .click()
        followers = self._get_names()
	# We find the users in following but not in the followers list and catch those *******
        not_following_back = [user for user in following if user not in followers]
        u_arent_following  = [user for user in followers if user not in following]
        print("People who aren't following you back - ",not_following_back)
        print()
        print("People you aren't following back - ", u_arent_following)

    def _get_names(self):
        sleep(5)
	# I made it 5 because by internet is already bad as it is.
        scroll_box = self.driver.find_element_by_xpath("/html/body/div[4]/div/div[2]")
        last_ht, ht = 0, 1
        while last_ht != ht:
            last_ht = ht
            sleep(1) 
	    #scroll to bottom of scrollbox and return the ht of the scrollbox
            ht = self.driver.execute_script("""
                arguments[0].scrollTo(0, arguments[0].scrollHeight); 
                return arguments[0].scrollHeight;
                """, scroll_box)
	#Converting list a tags into string format
        links = scroll_box.find_elements_by_tag_name('a')
        names = [name.text for name in links if name.text != '']
        # close button
        self.driver.find_element_by_xpath("/html/body/div[4]/div/div[1]/div/div[2]")\
            .click()
        return names   


my_bot = InstaBot('harikaapi_right', 'Harithedapfb25')
my_bot.get_unfollowers()
	