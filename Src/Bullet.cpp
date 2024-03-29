//
// Created by jesse on 02/12/2023.
//

#include <Components/VelocityComponent.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/TransformComponent.hpp>
#include <Components/RigidBodyComponent.hpp>
#include <Components/BoxCollisionComponent.hpp>
#include <EngineManagers/CollisionLayerManager.hpp>
#include "Bullet.hpp"

#include "Scripts/BulletActions.hpp"

Bullet::Bullet(size_t layer) {
    addComponent(std::make_unique<VelocityComponent>());
    auto &transform = tryGetComponent<TransformComponent>();
    auto sprite = std::make_unique<SpriteComponent>();
    sprite->spritePath = "Sprites/Bullet.png";
    sprite->spriteSize = std::make_unique<Vector2>(18, 8);
    sprite->sortingLayer = layer;
    sprite->orderInLayer = 2;
    sprite->tileOffset = std::make_unique<Vector2>(0, 0);
    transform.scale = std::make_unique<Vector2>(1, 1);
    auto rigidBody = std::make_unique<RigidBodyComponent>(CollisionType::DYNAMIC);
    rigidBody->gravityScale = 0.0f;
    rigidBody->collisionCategory = CollisionLayerManager::getInstance().getCategory("Bullet");
    rigidBody->collisionMask = CollisionLayerManager::getInstance().getMask("Bullet");
    addComponent(std::move(rigidBody));
    auto boxCollision = std::make_unique<BoxCollisionComponent>(Vector2(18, 8));
    boxCollision->isTrigger = false;
    addComponent(std::move(boxCollision));
    addComponent(std::move(sprite));
    addBehaviourScript(std::make_unique<BulletActions>(5000));
    setTag("Bullet");
}
