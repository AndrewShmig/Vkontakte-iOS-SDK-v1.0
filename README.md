##Vkontakte iOS SDK

* Appledoc по [этой](https://github.com/AndrewShmig/Vkontakte-iOS-SDK/tree/master/Vkontakte%20iOS%20SDK_Project/VkontakteSDK_Source/docs) ссылке.
* [Введение во Vkontakte iOS SDK v1.0](http://developing-ios-apps-with-andrew-shmig.blogspot.ru/2013/06/vkontakte-ios-sdk-v10.html)
* [Введение во Vkontakte iOS SDK v1.0 Хабр](http://habrahabr.ru/post/184560/)

##Пример
У нас будет одноэкранное приложение, поэтому авторизацию пользователем приложения повесим в:
````
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
````

и будет выглядеть этот метод следующим образом:

````
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // code
    
    [[VKConnector sharedInstance] setDelegate:self];
    [[VKConnector sharedInstance] startWithAppID:kVKAppID
                                      permissons:[kVKPermissionsArray componentsSeparatedByString:@","]];
    // code
}
````

В нашем случае константы ````kVKAppID```` и ````kVKPermissionsArray```` выглядят следующим образом:

````
static NSString *const kVKAppID = @"3541027";
static NSString *const kVKPermissionsArray = @"photos,friends,wall,audio,video,docs,notes,pages,status,groups,messages";
````

Устанавливая делегатом текущий класс мы можем обрабатывать 7 типов "уведомлений" в процессе авторизации (и в процессе 
осуществления запросов тоже) пользователем приложения:

1. VKConnector:willShowModalView:
2. VKConnector:willHideModalView:
3. VKConnector:accessTokenInvalidated:
4. VKConnector:accessTokenRenewalFailed:
5. VKConnector:accessTokenRenewalSucceeded:
6. VKConnector:connectionErrorOccured:
7. VKConnector:parsingErrorOccured:

Детали можно узнать из документации ````VKConnectorProtocol````.

После запуска приложения появится такое окно авторизации:

![modal view](http://s1.ipicture.ru/uploads/20130627/RHRTb93X.png)

Если пользователь авторизует наше приложение, что вызывается метод делегата ````VKConnector:accessTokenRenewalSucceeded:````,
в противном случае ````VKConnector:accessTokenRenewalFailed:````.
В случае, если во время запроса произошел сбой в сети и запрос не удалось выполнить, то будет вызван метод делегата 
````VKConnector:connectionErrorOccured:````, а метод ````VKConnector:parsingErrorOccured:````, если произошла ошибка
при парсинге ответа сервера социальной сети.

После получения токенов доступа мы можем совершать запросы от лица пользователя.
Подключите ````VKUser.h```` и используйте в таком ключе:
````
id myFriends = [[[VKUser currentUser] friends] online];
````
Если перед осуществление запроса выяснилось, что срок действия токена истёк, то будет вызван метод делегата 
````VKConnector:accessTokenInvalidated:```` в котором вы должны вызвать метод ````startWithAppID:permissions:```` класса
VKConnector, чтобы обносить токен доступа.

Запросы осуществляются *синхронно*, об этом не стоит забывать.


##License
Copyright (c) 2013 Andrew Shmig

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
