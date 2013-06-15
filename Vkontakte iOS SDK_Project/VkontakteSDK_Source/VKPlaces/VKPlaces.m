//
// Created by AndrewShmig on 5/28/13.
//
//
// Copyright (c) 2013 Andrew Shmig
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//

#import "VKPlaces.h"
#import "VKConnector.h"

@implementation VKPlaces
{
    
}

#pragma mark Visible VKPlaces methods
#pragma mark - places.add

- (id)addType:(NSUInteger)type title:(NSString *)title latitude:(CGFloat)latitude longitude:(CGFloat)longitude country:(NSUInteger)country city:(NSUInteger)city address:(NSString *)address
{
    NSDictionary *options = @{@"type": @(type),
                              @"title": title,
                              @"latitude": @(latitude),
                              @"longitude": @(longitude),
                              @"country": @(country),
                              @"city": @(city),
                              @"address": address};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesAdd
                                                 options:options
                                                   error:nil];
}

- (id)addType:(NSUInteger)type title:(NSString *)title latitude:(CGFloat)latitude longitude:(CGFloat)longitude country:(NSUInteger)country city:(NSUInteger)city
{
    return [self addType:type
                   title:title
                latitude:latitude
               longitude:longitude
                 country:country
                    city:city
                 address:@""];
}

- (id)addType:(NSUInteger)type title:(NSString *)title latitude:(CGFloat)latitude longitude:(CGFloat)longitude
{
    NSDictionary *options = @{@"type": @(type),
                              @"title": title,
                              @"latitude": @(latitude),
                              @"longitude": @(longitude)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesAdd
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.getById

- (id)byIDs:(NSArray *)placesIDs
{
    NSDictionary *options = @{@"places": [placesIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetById
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.search

- (id)searchCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesSearch
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.checkin

- (id)checkInCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesCheckin
                                                 options:options
                                                   error:nil];
}

- (id)checkInPlaceID:(NSUInteger)placeID text:(NSString *)text latitude:(CGFloat)latitude longitude:(CGFloat)longitude friendsOnly:(NSUInteger)friendsOnly
{
    NSDictionary *options = @{@"place_id": @(placeID),
                              @"text": text,
                              @"latitude": @(latitude),
                              @"longitude": @(longitude),
                              @"friends_only": @(friendsOnly)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesCheckin
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.getCheckins

- (id)checkinsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetCheckins
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.getTypes

- (id)types
{
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetTypes
                                                 options:@{}
                                                   error:nil];
}

#pragma mark - places.getCountries

- (id)countriesCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetCountries
                                                 options:options
                                                   error:nil];
}

- (id)countries
{
    NSDictionary *options = @{@"need_full": @1};
    
    return [self countriesCustomOptions:options];
}

#pragma mark - places.getRegions

- (id)regionsCuntryID:(NSUInteger)countryID
{
    NSDictionary *options = @{@"country": @(countryID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetRegions
                                                 options:options
                                                   error:nil];
}

- (id)regionsCuntryID:(NSUInteger)countryID searchQuery:(NSString *)query
{
    NSDictionary *options = @{@"country": @(countryID),
                              @"q": query};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetRegions
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.getStreeById

- (id)streetsByIDs:(NSArray *)streetsIDs
{
    NSDictionary *options = @{@"sids": [streetsIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetStreetById
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.getCountryById

- (id)countriesByIDs:(NSArray *)countriesIDs
{
    NSDictionary *options = @{@"cids": [countriesIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetCountryById
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.getCities

- (id)citiesCountryID:(NSUInteger)countryID
{
    NSDictionary *options = @{@"country": @(countryID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetCities
                                                 options:options
                                                   error:nil];
}

- (id)citiesCountryID:(NSUInteger)countryID searchQuery:(NSString *)query
{
    NSDictionary *options = @{@"country": @(countryID),
                              @"q": query};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetCities
                                                 options:options
                                                   error:nil];
}

#pragma mark - places.getCityById

- (id)citiesByIDs:(NSArray *)citiesIDs
{
    NSDictionary *options = @{@"cids": [citiesIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKPlacesGetCityById
                                                 options:options
                                                   error:nil];
}

@end