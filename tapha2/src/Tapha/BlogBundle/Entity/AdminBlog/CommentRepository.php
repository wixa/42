<?php

namespace Tapha\BlogBundle\Entity\AdminBlog;

use Doctrine\ORM\EntityRepository;
use Doctrine\Common\Collections\Criteria;

/**
 * CommentRepository
 *
 * This class was generated by the Doctrine ORM. Add your own custom
 * repository methods below.
 */
class CommentRepository extends EntityRepository
{
    /**
     * 
     * @return Criteria
     */
    static function getPubliedOrderedCriteria(){
        return  $criteria = Criteria::create()->andWhere(Criteria::expr()->gte('publied', date('Y-m-d H:i:s')))
                                              ->orderBy(array('created' => Criteria::ASC));
    }
    
    public function findOneByIpLast($ip){
        return $this->createQueryBuilder('a')
                    ->andWhere('a.ip = :ip')
                    ->orderBy('a.created' , 'DESC')
                    ->setMaxResults(1)
                    ->setParameter('ip', $ip)
                    ->getQuery()
                    ->getOneOrNullResult();
    }
}
