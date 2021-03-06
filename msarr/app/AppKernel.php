<?php

use Symfony\Component\HttpKernel\Kernel;
use Symfony\Component\Config\Loader\LoaderInterface;

class AppKernel extends Kernel
{
    public function registerBundles()
    {
        $bundles = array(
            new Symfony\Bundle\FrameworkBundle\FrameworkBundle(),
            new Symfony\Bundle\SecurityBundle\SecurityBundle(),
            new Symfony\Bundle\TwigBundle\TwigBundle(),
            new Symfony\Bundle\MonologBundle\MonologBundle(),
            new Symfony\Bundle\SwiftmailerBundle\SwiftmailerBundle(),
            new Symfony\Bundle\AsseticBundle\AsseticBundle(),
            new Doctrine\Bundle\DoctrineBundle\DoctrineBundle(),
            new Sensio\Bundle\FrameworkExtraBundle\SensioFrameworkExtraBundle(),
            new AppBundle\AppBundle(),
            new BlogBundle\BlogBundle(),
            new FOS\UserBundle\FOSUserBundle(),

            // new Sonata\NewsBundle\SonataNewsBundle(),
            // new Application\Sonata\NewsBundle\ApplicationSonataNewsBundle(),
            //new Sonata\FormatterBundle\SonataFormatterBundle(),
            //new Knp\Bundle\MarkdownBundle\KnpMarkdownBundle(),
        
            new Sonata\CoreBundle\SonataCoreBundle(),
            new Sonata\BlockBundle\SonataBlockBundle(),
            new Knp\Bundle\MenuBundle\KnpMenuBundle(),
            new Sonata\DoctrineORMAdminBundle\SonataDoctrineORMAdminBundle(),
            new Sonata\AdminBundle\SonataAdminBundle(),
            new FM\ElfinderBundle\FMElfinderBundle(),

            new ED\BlogBundle\EDBlogBundle(),
            new Knp\Bundle\PaginatorBundle\KnpPaginatorBundle(),
            new Doctrine\Bundle\FixturesBundle\DoctrineFixturesBundle(),
            new Stof\DoctrineExtensionsBundle\StofDoctrineExtensionsBundle(),
            new Eko\FeedBundle\EkoFeedBundle(),

            new Sonata\MediaBundle\SonataMediaBundle(),
            new Application\Sonata\MediaBundle\ApplicationSonataMediaBundle(),
            new Sonata\IntlBundle\SonataIntlBundle(),
            new JMS\SerializerBundle\JMSSerializerBundle(),

            new Sonata\EasyExtendsBundle\SonataEasyExtendsBundle(),
            // new Sonata\UserBundle\SonataUserBundle('FOSUserBundle'),
            // new Application\Sonata\UserBundle\ApplicationSonataUserBundle(),

            // new Sonata\ClassificationBundle\SonataClassificationBundle(),
            // new Application\Sonata\ClassificationBundle\ApplicationSonataClassificationBundle(),

            new Ivory\CKEditorBundle\IvoryCKEditorBundle(),
            

            new Liip\ThemeBundle\LiipThemeBundle(),
            new Liip\ImagineBundle\LiipImagineBundle(),

            new Evheniy\JqueryBundle\JqueryBundle(),
            new Evheniy\HTML5CacheBundle\HTML5CacheBundle(),
            new Evheniy\HTML5VertiTemplateBundle\HTML5VertiTemplateBundle(),
        );

        if (in_array($this->getEnvironment(), array('dev', 'test'))) {
            $bundles[] = new Symfony\Bundle\DebugBundle\DebugBundle();
            $bundles[] = new Symfony\Bundle\WebProfilerBundle\WebProfilerBundle();
            $bundles[] = new Sensio\Bundle\DistributionBundle\SensioDistributionBundle();
            $bundles[] = new Sensio\Bundle\GeneratorBundle\SensioGeneratorBundle();
        }

        return $bundles;
    }

    public function registerContainerConfiguration(LoaderInterface $loader)
    {
        $loader->load($this->getRootDir().'/config/config_'.$this->getEnvironment().'.yml');
    }
}
